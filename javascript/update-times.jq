. + {
	$id: [$start[0], (now | round), $bytes],
	"needsRating": true
} | tostring | gsub("(?=}|,\")"; "\n")
