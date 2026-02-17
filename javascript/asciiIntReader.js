const ar = (function asciiIntReader() {
	let input = require('fs').readFileSync(0);
	let offset = 0;
	return {
		nextInt(arr) {
			let single = (arr?.length == null);
			if (single) {
				arr = [0];
			}
			for (let i = 0; i < arr.length; ++i) {
				let byte;
				do {
					byte = input[offset++];
				} while (byte < 0x30 || byte > 0x39);
				if (byte == null) {
					break;
				}
				// byte is now a digit
				let negate = (input[offset - 2] == 0x2D);
				let natural = 0;
				do {
					natural = (10 * natural) + byte - 0x30;
					byte = input[offset++];
				} while (byte >= 0x30 && byte <= 0x39);
				// byte is no longer a digit
				--offset;
				arr[i] = negate ? -natural : natural;
			}
			return single ? arr[0] : arr;
		}
	};
})();
