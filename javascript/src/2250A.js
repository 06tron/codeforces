let t = ar.nextInt();
const out = [];
while (t--) {
	const n = ar.nextInt();
	const w = ar.nextInt(new Uint32Array(n));
	if (n & 1) {
		out.push("NO");
		continue;
	}
	let minFirst = w[0];
	for (let i = 2; i < n; i += 2) {
		if (w[i] < minFirst) {
			minFirst = w[i];
		}
	}
	let passing = true;
	for (let i = 1; i < n; i += 2) {
		if (w[i] + 1 >= minFirst) {
			passing = false;
			break;
		}
	}
	out.push(passing ? "YES" : "NO");
}
process.stdout.write(out.join('\n'));
// Began: 1785077069
// Ended: 1785078212
