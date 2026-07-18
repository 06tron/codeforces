let t = ar.nextInt();
const out = [];
while (t--) {
	const n = ar.nextInt();
	const p = ar.nextInt(new Uint32Array(n-1));
	const childCount = new Uint32Array(n); // zeros by default
	for (let i = 2; i <= n; ++i) {
		const p_i = p[i-2];
		childCount[p_i-1] += 1;
	}
	const ready = [];
	for (let i = 1; i <= n; ++i) {
		if (childCount[i-1] == 0) {
			ready.push(i);
		}
	}
	const childScores = Array(n);
	while (ready.length > 0) {
		const i = ready.pop();
		let iScore = 1;
		let depthShared = 0;
		let maxDepth = 0;
		for (let j = 0; j < childCount[i-1]; ++j) {
			const [cScore, cDepth] = childScores[i-1][j];
			iScore += cScore;
			if (cDepth > maxDepth) {
				depthShared = maxDepth;
				maxDepth = cDepth;
			} else if (cDepth > depthShared) {
				depthShared = cDepth;
			}
		}
		delete childScores[i-1];
		iScore += depthShared;
		if (i == 1) {
			out.push(iScore);
			break;
		}
		let parentScores = childScores[p[i-2]-1];
		if (parentScores === undefined) {
			childScores[p[i-2]-1] = parentScores = [];
		}
		parentScores.push([iScore, maxDepth+1]);
		if (childCount[p[i-2]-1] == parentScores.length) {
			ready.push(p[i-2]);
		}
	}
}
process.stdout.write(out.join('\n'));
// Began: 1784379256
// Ended: 1784391217
