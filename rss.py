import feedparser

url = "http://rss.ohmynews.com/rss/top.xml"
parser_rss = feedparser.parse(url)
for feed in parser_rss['entries']:
    print(feed.updated, feed.title)
