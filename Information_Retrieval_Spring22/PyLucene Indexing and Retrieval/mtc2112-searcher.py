import lucene
import os
from bs4 import BeautifulSoup
import glob
import pickle
import csv
import pandas as pd
import nltk
import sys
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


index_path = sys.argv[1]
index_path = File(index_path).toPath()
qry_path = sys.argv[2]
res_path = sys.argv[3] + '/search_result.txt'



def retrieve(index_path, qry, qnum):
    analyzer = StandardAnalyzer()
    directory = FSDirectory.open(index_path)
    searcher = IndexSearcher(DirectoryReader.open(directory))
    searcher.setSimilarity(BM25Similarity(1.8, 0.3))
    query = QueryParser("TEXT", analyzer).parse(qry)
    scoreDocs = searcher.search(query, 1000).scoreDocs

    i = 1
    for scoreDoc in scoreDocs:
        doc = searcher.doc(scoreDoc.doc)
        with open(res_path, 'a') as result:
          data_row = str(qnum) + ' Q0 ' + str(doc.get("DOCNO")) + ' ' + str(i) + ' ' + str(scoreDoc.score) + ' ' + str(i)
          result.write(data_row)
          result.write('\n')
        i = i + 1


query = open(qry_path)
query_anchor = BeautifulSoup(query, "html.parser")

num_list = []
title_list = []
desc_list = []
for each in query_anchor.find_all("num"):
    num_list.append(each.text)
for each in query_anchor.find_all("title"):
    title_list.append(each.text)
for each in query_anchor.find_all("desc"):
    desc_list.append(each.text)


choice = int(input("\n\nSearch using Only Query(1) or Query with description(2)?  "))

if choice == 1:
  for i in range(len(num_list)):
    retrieve(index_path, title_list[i], num_list[i])
elif choice == 2:
  for i in range(len(title_list)):
    temp = title_list[i] + ' ' + desc_list[i]
    retrieve(index_path, temp, num_list[i])
print("Search results saved!\n")
