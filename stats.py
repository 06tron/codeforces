import csv
import requests
import matplotlib.pyplot as plt

status = requests.get("https://codeforces.com/api/user.status?handle=06tron")
subs = status.json()["result"]
ids = []
cpm = []
minutes = []
ratings = []
# number of characters in template.cpp
template_chars = 152

with open("times.csv", 'r') as times:
	csv_rows = csv.reader(times)
	next(csv_rows)
	i = len(subs) - 1
	for row in csv_rows:
		id = int(row[0][:-1])
		c = row[0][-1:]
		while subs[i]["contestId"] != id or subs[i]["problem"]["index"] != c:
			i -= 1
		min = (int(row[4]) - int(row[2])) / 60
		if min < 500:
			ids.append(row[0])
			cpm.append((int(row[5]) - template_chars) / min)
			minutes.append(min)
			ratings.append(subs[i]["problem"]["rating"])

def makebar(x, y):
	ax = plt.gca()
	bars = ax.bar(x, y, width = 0.4)
	for i in range(len(x)):
		red = ((3500 - ratings[i]) / 2700)**2
		bars[i].set_color((red, 0, 0))
	ax.yaxis.grid()
	ax.set_axisbelow(True)

colors = {
	"axes.labelcolor": "white",
	"axes.edgecolor": "white",
	"xtick.color": "white",
	"ytick.color": "white"
}

with plt.rc_context(colors):
	makebar(ids, minutes)
	plt.ylabel("Minutes")
	plt.savefig("minutes.png", transparent=True)
	plt.clf()
	makebar(ids, cpm)
	plt.ylabel("Characters Per Minute")
	plt.savefig("cpm.png", transparent=True)
