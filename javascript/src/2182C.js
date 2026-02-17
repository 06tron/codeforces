const t = ar.nextInt();
const out = Array(t);
for (let h = 0; h < t; ++h) {
	const n = ar.nextInt();
	const a = ar.nextInt(new Uint16Array(n));
	const b = ar.nextInt(new Uint16Array(n));
	let goodJ = 0;
	for (let j = 0; j < n; ++j) {
		let success = 1;
		for (let l = 0; l < n; ++l) {
			if (a[l] >= b[(j+l) % n]) {
				success = 0;
				break;
			}
		}
		goodJ += success;
	}
	const c = ar.nextInt(a);
	let goodK = 0;
	for (let k = 0; k < n; ++k) {
		let success = 1;
		for (let l = 0; l < n; ++l) {
			if (b[l] >= c[(k+l) % n]) {
				success = 0;
				break;
			}
		}
		goodK += success;
	}
	out[h] = n * goodJ * goodK;
}
process.stdout.write(out.join('\n'));
// Began: 1771300299
// Ended: 1771304640
