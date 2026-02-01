const ar = (function asciiReader() { // 06tron
	const input = require('fs').readFileSync(0);
	let offset = 0;
	return {
		nextInt: function (arr) {
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
					break;
				}
				// byte is now a digit
				const negate = (input[offset - 2] == 0x2D);
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
		},
		nextStr: function (len) {
			if (len >= 0 && Number.isInteger(len)) {
				offset += len;
				return input.toString('latin1', offset - len, offset);
			}
			let byte;
			do {
				byte = input[offset++];
			} while (byte == 0x20 || (byte >= 0x09 && byte <= 0x0D));
			if (byte === undefined) {
				return '';
			}
			// byte is a non-whitespace character
			const start = offset - 1;
			do {
				byte = input[offset++];
			} while (byte != 0x20 && (byte < 0x09 || byte > 0x0D));
			// byte is no longer a non-whitespace character
			--offset;
			return input.toString('latin1', start, offset);
		},
		skip: function (len) {
			offset += len;
		}
	};
})();
