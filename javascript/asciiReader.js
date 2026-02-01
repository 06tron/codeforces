const ar = (function asciiReader() { // 06tron
	const input = require('fs').readFileSync(0);
	let offset = 0;
	return {
		nextNat: function (arr = null) {
			const single = (arr?.length === undefined);
			if (single) {
				arr = new Array(1);
			}
			for (let i = 0; i < arr.length; ++i) {
				let byte;
				do {
					byte = input[offset++];
				} while (byte < 0x30 || byte > 0x39);
				if (byte === undefined) {
					arr.fill(NaN, i);
					break;
				}
				let natural = 0;
				do {
					natural = (10 * natural) + byte - 0x30;
					byte = input[offset++];
				} while (byte >= 0x30 && byte <= 0x39);
				--offset;
				arr[i] = natural;
			}
			return single ? arr[0] : arr;
		},
		nextStr: function (len) {
			offset += len;
			return input.toString('latin1', offset - len, offset);
		}
	};
})();
