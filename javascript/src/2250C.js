function mSearch(n, b) {
	for (let m = n; m >= 1; --m) {
		let j = 1;
		for (let i = 1; i <= n; ++i) {
			const k = 4 * (i - 1);
			if ((j < b[k] || j > b[k + 1]) && (m - j + 1 < b[k + 2] || m - j + 1 > b[k + 3])) {
				if (j == m) {
					return m;
				}
				j++;
			}
		}
	}
	return 0;
}

let t = ar.nextInt();
const out = new Uint16Array(t);
const b = new Uint16Array(2e4);
while (t--) {
	const n = ar.nextInt();
	ar.nextInt(b.subarray(0, n * 4));
	out[out.length - t - 1] = mSearch(n, b);
}
process.stdout.write(out.join('\n'));
