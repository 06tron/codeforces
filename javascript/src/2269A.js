let t = ar.nextInt();
const out = [];
while (t--) {
	const n = ar.nextInt();
	const k = ar.nextInt();
	out.push(2 * k + (2 << n - k) - 2);
}
process.stdout.write(out.join('\n'));
