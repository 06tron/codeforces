import sys
import csv
import time
import requests
import matplotlib.pyplot as plt

# If arguments are passed (by Makefile), then use them to
#   complete the unfinished times.csv entry.
# subs is an array of all my submissions, which I think are
#   sorted by time. The elements are codeforces Submission
#   objects: https://codeforces.com/apiHelp/objects#Submission
if len(sys.argv) > 1:
	arg = sys.argv[1]
	id = int(arg[arg.find('-')+1:-5])
	letter = arg[-5:-4]
	insert = time.strftime(",%Y-%m-%d %H:%M:%S,%s,", time.gmtime())
	insert += sys.argv[2] + ','
	link = "https://codeforces.com/api/user.status?handle=06tron"
	subs = requests.get(link).json()["result"]
	with open("times.csv", 'a') as times:
		for s in subs:
			if id == s["contestId"] and letter == s["problem"]["index"]:
				insert += str(s["problem"]["rating"]) + '\n'
				times.write(insert)
				break

# The number of characters in template.cpp
template_chars = 152

# Problems that took this long were most likely not completed in
#   one sitting, so they shouldn't be graphed.
minute_cutoff = 500

# These four arrays are all the same length, as the elements
#   correspond to the bars in the generated plots.
ids = []
cpm = []
minutes = []
ratings = []

# Read times.csv and subs simultaneously, extracting each
#   problem's rating and updating the four arrays
with open("times.csv") as times:
    reader = csv.DictReader(times)
    for row in reader:
        min = (int(row["end_seconds"]) - int(row["start_seconds"])) / 60
        if min < minute_cutoff:
            ids.append(row["id"])
            cpm.append((int(row["characters"]) - template_chars) / min)
            minutes.append(min)
            ratings.append(int(row["rating"]))

# Set up a bar plot with horizontal lines, and change the colors
#   of the bars to represent their problem's rating. Darker red
#   means more difficult.
def make_bar(x, y):
    ax = plt.gca()
    bars = ax.bar(x, y, width=0.8)
    for i in range(len(x)):
        red = ((3500 - ratings[i]) / 2700)**2
        bars[i].set_color((red, 0, 0))
    ax.yaxis.grid()

# Make most things white so the plots are easily readable on a
#   dark background. Red gridlines make it easier to see the
#   differences in bar colors.
colors = {
    "axes.labelcolor": "white",
    "axes.edgecolor": "white",
    "xtick.color": "white",
    "ytick.color": "white",
	"grid.color": "red"
}

# Generate two bar charts, one for minutes to solve a problem,
#   and the other for typing speed while solving.
with plt.rc_context(colors):
    make_bar(ids, minutes)
    plt.ylabel("Minutes")
    plt.savefig("minutes.png", transparent=True)
    plt.clf()
    make_bar(ids, cpm)
    plt.ylabel("Characters Per Minute")
    plt.savefig("cpm.png", transparent=True)
