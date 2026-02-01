let t = ar.nextInt();
let out = new Uint32Array(t);
for (let i = 0; i < t; ++i) {
	const n = ar.nextInt();
	let x = ar.nextInt();
	const a = ar.nextInt(new Uint32Array(n));
	a.sort();
	let h = a[0];
	let width = 1;
	while (true) {
		while (width < n && a[width] == a[width - 1]) {
			++width;
		}
		const vol = (a[width] - a[width - 1]) * width;
		if (width == n || vol > x) {
			break;
		}
		x -= vol;
		h = a[width];
		++width;
	}
	out[i] = Math.floor(h + x / width);
}
process.stdout.write(out.join('\n'));
