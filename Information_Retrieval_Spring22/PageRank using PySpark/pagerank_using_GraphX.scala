
import org.apache.spark.graphx.GraphLoader
val graph = GraphLoader.edgeListFile(sc, "Wiki-Vote.txt")
val t1 = System.nanoTime
val ranks = graph.pageRank(0.0001).vertices
val duration = (System.nanoTime - t1) / 1e9d
println("Total time in seconds ", duration)

// to generate node_names file from original
// data use helper.py
val users = sc.textFile("node_names.txt").map { line =>
  val fields = line.split("\t")
  (fields(0).toLong, fields(1))
}
val ranksByUsername = users.join(ranks).map {
  case (id, (username, rank)) => (username, rank)
}

// ranks not sorted
// for sorting the ranks use helper.py
ranksByUsername.coalesce(1).saveAsTextFile("PySpark-GraphX-result.txt")
println(ranksByUsername.collect().mkString("\n"))



