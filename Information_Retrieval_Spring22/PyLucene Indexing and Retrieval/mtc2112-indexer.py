import lucene
import os
import sys
from bs4 import BeautifulSoup
import glob
import pickle
import csv
import pandas as pd
import nltk
nltk.download('punkt')
from nltk import word_tokenize
porter = nltk.PorterStemmer()
from java.io import File

lucene.initVM()

from org.apache.lucene.index import IndexReader
from org.apache.lucene.search import IndexSearcher
from org.apache.lucene.index import DirectoryReader
from org.apache.lucene.queryparser.classic import QueryParser
from org.apache.lucene.search.similarities import BM25Similarity

from org.apache.lucene.analysis.standard import StandardAnalyzer
from org.apache.lucene.analysis.en import EnglishAnalyzer
from org.apache.lucene.index import IndexWriter, IndexWriterConfig
from org.apache.lucene.store import SimpleFSDirectory, FSDirectory
import org.apache.lucene.document as document

data_path = sys.argv[1]
index_path = sys.argv[2]
index_path = File(index_path).toPath()



header = ['DOCNO', 'TITLE', 'TEXT']
cwd = os.getcwd()
save_path = cwd + '/data.csv'


with open(save_path, 'w', encoding='UTF8') as f:
    writer = csv.writer(f)
    writer.writerow(header)


bdnews_path = data_path + '/en_BDNews24/*'
telegraph_path = data_path + '/en_TheTelegraph_2001-2010/*'

bdnews_files = []
for subfolder in glob.glob(bdnews_path):
  temp = subfolder + '/*'
  bdnews_files.append(glob.glob(temp))

for i in range(len(bdnews_files)):
  for eachpath in bdnews_files[i]:
    news_file = open(eachpath)
    anchor = BeautifulSoup(news_file, "html.parser")
    datarow = [anchor.docno.text, anchor.title.text, anchor.text.strip('\n').split('\n')[3]]
    with open(save_path, 'a', encoding='UTF8') as f:
      writer = csv.writer(f)
      writer.writerow(datarow)


telegraph_files = []
for subfolder in glob.glob(telegraph_path):
  temp = subfolder + '/*/*'
  telegraph_files.append(glob.glob(temp))

for i in range(len(telegraph_files)):
  for eachpath in telegraph_files[i]:
    if os.path.isfile(eachpath):
        news_file = open(eachpath)
        anchor = BeautifulSoup(news_file, "html.parser")
        datarow = [anchor.docno.text, 'None', anchor.text.strip('\n')]
        with open(save_path, 'a', encoding='UTF8') as f:
          writer = csv.writer(f)
          writer.writerow(datarow)


###             indexing with standardanalyzer              ###



indexDir = FSDirectory.open(index_path)
writerConfig = IndexWriterConfig(StandardAnalyzer())
writer = IndexWriter(indexDir, writerConfig)


def indexNews(docno, title, news):
    doc = document.Document()
    doc.add(document.Field("DOCNO", docno, document.TextField.TYPE_STORED))
    doc.add(document.Field("TITLE", title, document.TextField.TYPE_STORED))
    doc.add(document.Field("TEXT", news, document.TextField.TYPE_STORED))
    writer.addDocument(doc)
def closeWriter():
    writer.close()

def makeIndex(file_path):
    df = pd.read_csv(file_path)
    docid = 0
    for i in df.index:
        # print(docid, "-", df['TITLE'][i])
        indexNews(df['DOCNO'][i], df['TITLE'][i], df['TEXT'][i])
        docid += 1
    print("Indexing done!\n")

makeIndex(save_path)
closeWriter()

# remove temporary csv
if(os.path.exists(save_path) and os.path.isfile(save_path)):
  os.remove(save_path)
