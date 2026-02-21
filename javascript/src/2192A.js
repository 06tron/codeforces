let t = ar.nextInt();
const out = [];
while (t--) {
	const n = ar.nextInt();
	const s = ar.nextStr();
	let hasPair = false;
	let blocks = 1;
	for (let i = 1; i < n; ++i) {
		if (s[i] === s[i-1]) {
			hasPair = true;
		} else {
			++blocks;
		}
	}
	if (s[0] !== s[n-1] && hasPair) {
		++blocks;
	}
	out.push(blocks);
}
process.stdout.write(out.join('\n'));
// Began: 1771684669
// Ended: 1771686125
