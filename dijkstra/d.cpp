#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>


#define MAX_INT 999999999999

using namespace std;


class DF{
    public:
        float dis;
        int pre;
};

class Edge{
    public:
        int edge;
        float weight;       
};

class Vertice{
    public:
        vector<Edge> edges;
        vector<DF> df;
};


class Heap{
    public:
        vector<Edge> edges;
        vector<int> pos;

        void add ( Edge novo){
            int i = edges.size();
            pos[novo.edge] = i;
            edges.push_back(novo);
            while(i >0  && edges[i].weight < edges[ (i-1)/2 ].weight ){
                Edge temp = edges[i];
                edges[i] = edges[(i-1)/2];
                edges[(i-1)/2] = temp;
                
                pos[edges[i].edge] = i;
                pos[edges[(i-1)/2].edge] = (i-1)/2;

                i = (i-1)/2;
            }
        }

        void update(int v, float dis){
            for(int i =0; i < edges.size() ; i++){
                if(v == edges[i].edge){
                    edges[i].weight = dis;
                    build();
                    return;
                }
            }
            Edge novo;
            novo.edge = v;
            novo.weight = dis;
            add(novo);
        }

        Edge extract(){
            if(!edges.size()){
                Edge a;
                a.edge= -1;
                a.weight =-1;
                return a;
            }
            Edge temp = edges[0];
            edges[0] = edges[edges.size() - 1];
            edges[edges.size() - 1] = temp;
            pos[edges[edges.size() - 1].edge] = -1;
            edges.pop_back();

            heapfy(0);
            return temp;

        }

        void build(){
            for(int i= (edges.size()/2 -1) ; i >= 0 ; i--){
                heapfy(i);
            }
        }
        void heapfy(int i){
            int l =2*i +1, r = 2*i+2, m = i;
            if( l < m && edges[l].weight < edges[m].weight){
                m=l;
            }
            if(r <  m && edges[r].weight < edges[m].weight){
                m = r;
            }
            if(m!=i){
                Edge temp=edges[i];
                edges[i] = edges[m];
                edges[m] = temp;
                pos[edges[i].edge] = i;
                pos[edges[m].edge] = m;
                heapfy(m);
            }
        }
};



class Graph{
    public:
        vector<Vertice> vertices;

        void add(){
            Vertice novo;
            vertices.push_back(novo);
        }

        void bind(int a, int b, int w){
            Edge novo;
            novo.edge = b;
            novo.weight = w;
            vertices[a].edges.push_back(novo);
        }

        vector<DF> dijkstra(int s){
            vector<DF> df;
            DF novo;
            novo.dis = MAX_INT;
            novo.pre = -1;
            df.resize( vertices.size());
            df.assign( vertices.size(), novo);

            df[s].dis =0;
            Heap C;
            C.pos.resize(vertices.size());
            C.pos.assign(vertices.size( ), -1);

            Edge p;
            p.edge = s;
            p.weight = 0;
            C.add(p);
            for(int i =0; i < vertices.size() ; i++){
                Edge uv = C.extract();
                int u = uv.edge;
                //printf("extracted %d\n",u );
                Vertice e = vertices[uv.edge];
                for(int j =0; j <e.edges.size() ;j++ ){
                    int v = e.edges[j].edge;
                    float w  = e.edges[j].weight;
                    if(df[u].dis + w < df[v].dis){
                        df[v].dis = df[u].dis + w;
                        df[v].pre = u;
                        //printf("tryingh update %d\n",v);
                        C.update(v, df[v].dis);
                    }
                }
            }
            return df;
        }

        void path(int s){
            printf("\ndistances for %d\n", s);
            vertices[s].df = dijkstra(s);
            for(int i=0; i < vertices[s].df.size() ; i++){
                printf("%d : dis %.2f pre %d\n",i, vertices[s].df[i].dis,vertices[s].df[i].pre );
            }
        }

        void show(){
            printf("\n");
            for(int i=0 ; i<vertices.size(); i++){
                printf("\n- %d :",i);
                for(int j=0; j<vertices[i].edges.size() ; j++){
                    printf(" (e:%d, w:%.2f)" ,vertices[i].edges[j].edge , vertices[i].edges[j].weight);
                }
            }
        }
};



int main(){
    
    Graph graph;

    char comando[50];
    scanf(" %s", comando);
    while(strcmp(comando, "q") !=0){
        if(strcmp(comando, "a") == 0){
            int a; scanf(" %d",&a);
            while(a--){
                graph.add();
            }
        }
        if(strcmp(comando, "b") == 0){
            int a, b;
            float w;
            scanf(" %d%d%f",&a, &b, &w);
            graph.bind(a,b,w);
            

        }

        if(strcmp(comando, "dijkstra") == 0){
            int a;
            scanf(" %d",&a);

            graph.path(a);
            printf("\n");
        }

        if(strcmp(comando, "dijk-all") == 0){
            int a = graph.vertices.size();
            for(int i=0; i < graph.vertices.size() ; i++){
                graph.path(i);
            }
            printf("\n");
        }

        if(strcmp(comando, "show") == 0){
            graph.show();
            printf("\n");
        }
        scanf(" %s", comando);
    }

}