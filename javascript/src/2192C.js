let t = ar.nextInt();
const out = [];
while (t--) {
	const n = ar.nextInt();
	const h = BigInt(ar.nextInt());
	const k = BigInt(ar.nextInt());
	const a = ar.nextInt(new Int32Array(n));
	const sums = new Array(n);
	const mins = new Int32Array(n);
	sums[0] = BigInt(a[0]);
	mins[0] = a[0];
	for (let i = 1; i < n; ++i) {
		sums[i] = BigInt(a[i]) + sums[i-1];
		mins[i] = a[i] < mins[i-1] ? a[i] : mins[i-1];
	}
	const maxes = new Int32Array(n-1);
	maxes[n-2] = a[n-1];
	for (let i = n-3; i >= 0; --i) {
		maxes[i] = a[i+1] > maxes[i+1] ? a[i+1] : maxes[i+1];
	}
	const reloads = h / sums[n-1];
	const remaining = h % sums[n-1];
	if (remaining === 0n) { // reloads cannot also be 0
		out.push((BigInt(n) + k) * reloads - k);
		continue;
	}
	let j;
	for (j = 0; j < n-1; ++j) {
		const swap = sums[j] + BigInt(maxes[j] - mins[j]);
		if (swap >= remaining || sums[j] >= remaining) {
			break;
		}
	}
	out.push((BigInt(n) + k) * reloads + BigInt(j + 1));
}
process.stdout.write(out.join('\n'));
// Began: 1771688587
// Ended: 1771696856
