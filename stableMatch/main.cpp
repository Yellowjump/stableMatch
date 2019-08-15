#include <iostream>
#include <vector>
using namespace std;
class People{
public:
    vector<int> likeRank;
    int cp=-1;//-1表示未配对
    int ask=0;//向第几个woman
};
int main() {
    vector<People> men,women;
    int mannum=0,initnum=0;
    cout<<"input man number:"<<endl;
    cin>>mannum;
    while(initnum++<mannum){
        People oneman=People();
        for(int i=0;i<mannum;i++){
            int womanindex=0;
            cin>>womanindex;
            
            oneman.likeRank.push_back(womanindex);
            
        }
        men.push_back(oneman);
    }
    cout << "men init\n";
    
    initnum=0;
    while(initnum++<mannum){
        People onewomen=People();
        for(int i=0;i<mannum;i++){
            int womanindex=0;
            cin>>womanindex;
            
            onewomen.likeRank.push_back(womanindex);
        }
        women.push_back(onewomen);
    }
    cout << "women init\n";
    
    while(1){
        //如果所有mancp都！=-1；break
        bool flag=true;
        for(int i=0;i<mannum;i++){
            if(men[i].cp==-1){
                flag=false;
                break;
            }
        }
        if(flag)break;
        for(int i=0;i<mannum;i++){
            if(men[i].cp==-1){
                People &w=women[men[i].likeRank[men[i].ask]];
                if(w.cp==-1){//woman co==-1
                    men[i].cp=men[i].likeRank[men[i].ask];
                    w.cp=i;
                }
                else{
                    vector<int>::iterator has=find(w.likeRank.begin(), w.likeRank.end(), w.cp);
                    vector<int>::iterator lover=find(w.likeRank.begin(), w.likeRank.end(), i);
                    if(has>lover){
                        //交换
                        men[w.cp].cp=-1;
                        w.cp=i;
                    }
                }
                men[i].ask++;
            }
            
        }
    }
    cout<<"man"<<"\twoman"<<endl;
    for(int i=0;i<mannum;i++){
        cout<<i<<"\t"<<men[i].cp<<endl;
    }
    return 0;
}
