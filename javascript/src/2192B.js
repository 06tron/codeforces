let t = ar.nextInt();
const out = [];
while (t--) {
	const n = ar.nextInt();
	const s = ar.nextStr();
	let ones = [];
	let zeros = [];
	for (let i = 0; i < n; ++i) {
		if (s[i] === '1') {
			ones.push(i);
		} else {
			zeros.push(i);
		}
	}
	const good1 = ones.length % 2 == 0;
	const good0 = zeros.length % 2 == 1;
	if (!good1 && !good0) {
		out.push('-1');
		continue;
	}
	let min;
	if (good1 && good0) {
		min = ones.length < zeros.length ? ones.length : zeros.length;
	} else if (good1) {
		min = ones.length;
	} else {
		min = zeros.length;
	}
	out.push(min);
	if (min === 0) {
		continue;
	}
	let i1 = 0;
	let i0 = 0;
	let steps = [];
	for (let i = 0; i < min; ++i) {
		if (min % 2 == 0) {
			steps.push(ones[i1++] + 1);
		} else {
			steps.push(zeros[i0++] + 1);
		}
	}
	out.push(steps.join(' '));
}
process.stdout.write(out.join('\n'));
// Began: 1771686094
// Ended: 1771688569
