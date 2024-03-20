#include "Assistance.h"					// 辅助软件包
#include "AdjMatrixUndirGraph.h"		// 邻接矩阵无向图

int main(void)
{
    try									// 用try封装可能出现异常的代码
	{
		char vexs[] = {'A', 'B', 'C', 'D', 'E'};
		int m[5][5] = {
			{0, 4, 1, 1, 1},
			{5, 0, 1, 1, 7},
			{7, 1, 0, 0, 1},
			{1, 1, 1, 0, 7},
			{1, 8, 1, 0, 0},
		};
		char c = '0', e, e1, e2;
		int n = 5, v, v1, v2;

		AdjMatrixUndirGraph<char> g(vexs, n, 7);

		for (int u = 0; u < n; u++)
			for (int v = 0; v < n; v++)
				if ( u!=v && m[u][v] != 0) g.InsertArc(u, v, m[u][v]);

	    while (c != '9')	{
            cout << endl << "1. 图清空.";
            cout << endl << "2. 显示图.";
            cout << endl << "3. 取指定顶点的值.";
            cout << endl << "4. 设置指定顶点的值.";
            cout << endl << "5. 删除顶点.";
            cout << endl << "6. 插入顶点.";
            cout << endl << "7. 删除边.";
            cout << endl << "8. 插入边.";
		    cout << endl << "9. 入读出度";
		    cout << endl << "选择功能(1~9):";
		    cin >> c;
		    switch (c) 		{
			    case '1':
			        g.Clear();
				    break;
			    case '2':
                    if (g.IsEmpty())
                        cout << "该图为空。" << endl;
                    else 
			            g.Display();
				    break;
			    case '3':
			        cout << endl << "输入顶点序号（图的顶点序号从0开始）:";
			        cin >> v;
		            g.GetElem(v, e);
		            cout << "序号为" << v << "的顶点为" << e;
			        break;
			    case '4':
			        cout << endl << "输入顶点序号（图的顶点序号从0开始）:";
			        cin >> v;
			        cout << endl << "输入" << v <<"号顶点的值:";
			        cin >> e;
		            g.SetElem(v, e);
			        break;
			    case '5':
			        cout << endl << "输入被删除顶点的值:";
			        cin >> e;
		            g.DeleteVex(e);
			        break;
			    case '6':
			        cout << endl << "输入插入顶点的值:";
			        cin >> e;
		            g.InsertVex(e);
			        break;
			    case '7':
			        cout << endl << "输入与被删除边关联的两个顶点值:";
			        cin >> e1 >> e2;
			        v1 = g.GetOrder(e1);
			        v2 = g.GetOrder(e2);
		            g.DeleteArc(v1, v2);
			        break;
			    case '8':
			        cout << endl << "输入与插入边关联的两个顶点值（和权重）:";
                    int a;
			        cin >> e1 >> e2 >> a;
			        v1 = g.GetOrder(e1);
			        v2 = g.GetOrder(e2);
		            g.InsertArc(v1, v2, a);
			        break;
                case '9':
			        cout << endl << "输入顶点求入度和出度:";
                    int aaa;
                    cin >> aaa;
                    cout << g.CountOutDegree(aaa) << endl;
                    cout << g.CountInDegree(aaa) << endl;

       	      }
         }
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}
