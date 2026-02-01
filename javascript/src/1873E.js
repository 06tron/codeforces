let t = ar.nextInt();
while (t--) {
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
	console.log(Math.floor(h + x / width));
}
