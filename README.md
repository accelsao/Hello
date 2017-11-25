# Problem queue
# Problem category

1.最短路(Floyd、Dijstra,BellmanFord)  2.最小生成树(先写个prim,kruscal要用并查集，不好写) 3.大数（高精度）加减乘除 4.二分查找. (代码可在五行以内) 5.叉乘、判线段相交、然后写个凸包.  6.BFS、DFS,同时熟练hash表(要熟，要灵活,代码要简) 7.数学上的有：辗转相除（两行内），线段交点、多角形面积公式. 8. 调用系统的qsort, 技巧很多，慢慢掌握. 9. 任意进制间的转换   第二阶段：练习复杂一点，但也较常用的算法。 如：  1. 二分图匹配（匈牙利），最小路径覆盖 2. 网络流，最小费用流。 3. 线段树. 4. 并查集。  5. 熟悉动态规划的各个典型：LCS、最长递增子串、三角剖分、记忆化dp 6.博弈类算法。博弈树，二进制法等。 7.最大团，最大独立集。 8.判断点在多边形内。 9. 差分约束系统.  10. 双向广度搜索、A*算法，最小耗散优先.    相关的知识  图论     路径问题          0/1边权最短路径         BFS          非负边权最短路径（Dijkstra）             可以用Dijkstra解决问题的特征         负边权最短路径         Bellman-Ford              Bellman-Ford的Yen-氏优化             差分约束系统         Floyd              广义路径问题             传递闭包 
            极小极大距离 / 极大极小距离         Euler Path / Tour             圈套圈算法              混合图的 Euler Path / Tour         Hamilton Path / Tour              特殊图的Hamilton Path / Tour 构造       生成树问题         最小生成树         第k小生成树         最优比率生成树         0/1分数规划         度限制生成树       连通性问题          强大的DFS算法         无向图连通性             割点             割边             二连通分支             有向图连通性             强连通分支             2-SAT             最小点基       有向无环图         拓扑排序              有向无环图与动态规划的关系       二分图匹配问题          一般图问题与二分图问题的转换思路         最大匹配              有向图的最小路径覆盖             0 / 1矩阵的最小覆盖         完备匹配         最优匹配         稳定婚姻       网络流问题          网络流模型的简单特征和与线性规划的关系         最大流最小割定理         最大流问题              有上下界的最大流问题                 循环流 
        最小费用最大流 / 最大费用最大流       弦图的性质和判定   组合数学       解决组合数学问题时常用的思想         逼近          递推 / 动态规划     概率问题         Polya定理    计算几何 / 解析几何       计算几何的核心：叉积 / 面积     解析几何的主力：复数       基本形         点          直线，线段         多边形       凸多边形 / 凸包          凸包算法的引进，卷包裹法       Graham扫描法          水平序的引进，共线凸包的补丁       完美凸包算法       相关判定         两直线相交         两线段相交          点在任意多边形内的判定         点在凸多边形内的判定       经典问题         最小外接圆              近似O(n)的最小外接圆算法         点集直径              旋转卡壳，对踵点         多边形的三角剖分 

Segment Tree

樹狀數組原理+求逆序數對

BIT 

二次剩餘

STATE 搜尋 http://www.csie.ntnu.edu.tw/~u91029/State.html#1

MATCH

瓶頸生成樹

LCA http://www.csie.ntnu.edu.tw/~u91029/Graph2.html

RMQ

樹狀DP

kruskal SPFA 各種問題http://www.csie.ntnu.edu.tw/~u91029/SpanningTree.html#2

dlx

edmondd 朱劉

有向最小生成樹

dp優化 http://pisces.ck.tp.edu.tw/~peng/index.php?action=showfile&file=fe8e302bf69142773c541b1133e43c7413a560a38 四邊形優化http://chino.taipei/code-2016-0402Algorithm-DP%E5%84%AA%E5%8C%96%E4%B9%8B%E5%9B%9B%E9%82%8A%E5%BD%A2%E4%B8%8D%E7%AD%89%E5%BC%8F%E5%84%AA%E5%8C%96/

Ore's Theorem

Knight's Tour

樹鍊剖分


DP-插頭DP -http://www.csie.ntnu.edu.tw/~u91029/DynamicProgramming.html#1

莫隊算法 區間眾數

# Hyperlinks

https://www.math.ucla.edu/~tom/Game_Theory/Contents.html game theory 論文

http://ykgsmudq.com/%E7%AE%97%E6%B3%95%E6%95%B4%E7%90%86/ 算法整理

http://hzwer.com/1234.html 算法集庫

http://www-igm.univ-mlv.fr/~lecroq/string/index.html STRING MATCHING ALGORITHMS

# Mood notes
堀北鈴音<3 

最近開始
再次面對樹
好崩潰qq

不想看樹之後
又快被flow給打趴了...
17/9/17

圖真是太有趣了
不過混合圖的歐拉路徑寫不出來qq
繼續往postman前進
17/10/9

hamilton euler postman 暫時結束
回到樹鍊剖分..難阿
17/10/15

插頭DP真他X的難...ㄏㄏ
17/10/21

Nim 好像玩太久了 不小心就入坑了
17/11/03

吉普莉爾&史蒂芙 <3
樹也是坑阿 太可怕了
17/11/04

有鑒於沒題解就無法AC
RE:0 N題解practice
on codeforceB
17/11/14

CF解題 UVA練題 ZJ出題 
寶石之國讚
17/11/16

# Problem story

1:遊戲人生

2:Overlord

3:RE0

4:美好世界

5:實力主義

# Blog reference

http://www.cnblogs.com/lidaxin/

http://morris821028.github.io/

http://medalplus.com/

http://blog.sina.com.cn/s/blog_e96c26d20102v50h.html
