import csv
import requests
import matplotlib.pyplot as plt

status = requests.get("https://codeforces.com/api/user.status?handle=06tron")
subs = status.json()["result"]
ids = []
ratings = []
minutes = []

with open("times.csv", 'r') as times:
	csvrows = csv.reader(times)
	next(csvrows)
	i = len(subs) - 1
	for row in csvrows:
		id = int(row[0][:-1])
		c = row[0][-1:] # field 0 is "id"
		while subs[i]["contestId"] != id or subs[i]["problem"]["index"] != c:
			i -= 1
		min = (int(row[4]) - int(row[2])) // 60
		if min < 500:
			ids.append(row[0])
			minutes.append(min) # fields 2 and 4 are start and end seconds
			ratings.append(subs[i]["problem"]["rating"])

bars = plt.bar(ids, minutes, width = 0.4)
for i in range(len(bars)):
	red = (3500 - ratings[i]) / 2700
	red *= red
	bars[i].set_color((red, 0, 0))
plt.ylabel("Minutes")
plt.savefig("stats.png")
