function restrict(set, s, t) {
	const subset = [];
	for (let i = 0; i < set.length; i += 2) {
		if (s > set[i + 1] || t < set[i]) {
			subset.push(set[i], set[i + 1]);
			continue;
		}
		if (s > set[i]) { // && s <= set[i + 1]
			subset.push(set[i], s - 1);
		}
		if (t < set[i + 1]) { // && t >= set[i]
			subset.push(t + 1, set[i + 1]);
		}
	}
	return subset;
}

function contains(set, e) {
	for (let i = 0; i < set.length; i += 2) {
		if (e >= set[i] && e <= set[i + 1]) {
			return true;
		}
	}
	return false;
}

function greedyLength(i, length, mSet, n, bounds, stack, maxLength) {
	let validLength = 0;
	for (; i <= n; ++i) {
		if (length + n - i + 1 <= maxLength) {
			break;
		}
		if (mSet.at(-1) <= maxLength) {
			break;
		}
		const k = 4 * (i - 1);
		const l = bounds[k];
		const r = bounds[k + 1];
		const j = length + 1;
		if (j >= l && j <= r) {
			continue;
		}
		const u = bounds[k + 2];
		const v = bounds[k + 3];
		const mSubset = restrict(mSet, u + j - 1, v + j - 1);
		if (mSubset.length == 0) {
			continue;
		}
		stack.push([i + 1, length, mSet]);
		++length;
		mSet = mSubset;
		if (contains(mSet, length)) {
			validLength = length;
		}
	}
	return validLength;
}

let t = ar.nextInt();
const out = new Uint16Array(t);
const bounds = new Uint16Array(2e4);
const stack = [];
while (t--) {
	const n = ar.nextInt();
	ar.nextInt(bounds.subarray(0, n * 4));
	let maxLength = greedyLength(1, 0, [0, n], n, bounds, stack, 0);
	while (stack.length > 0) {
		const validLength = greedyLength(...stack.pop(), n, bounds, stack, maxLength);
		if (validLength > maxLength) {
			maxLength = validLength;
		}
	}
	out[out.length - t - 1] = maxLength;
}
process.stdout.write(out.join('\n'));
