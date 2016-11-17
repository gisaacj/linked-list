#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct student{
	char id[10];
	char name[10];
	char sex[4];
	char home[40];
	char tele[16];
	float chinese;
	float math;
	float english;
	float aver;
	int level;
	float clmate;
	float moral;
	float techer;
	float last_score;
	int last_level;
};

class Student{
	public:
		student stu;
		Student *next;
		Student(){}
	    Student(student s){
	        stu=s;
	        next=NULL;
	        stu.aver=(stu.chinese+stu.math+stu.english)/3.0;
	        stu.last_score=(stu.aver*0.6+stu.clmate*0.1+stu.moral*0.1+stu.techer*0.2);
	    }
	    void setst(student s){
	    	stu=s;
		}
		void setstu(student s){
			stu=s;
			stu.aver=(stu.chinese+stu.math+stu.english)/3.0;
			stu.last_score=(stu.aver*0.6+stu.clmate*0.1+stu.moral*0.1+stu.techer*0.2);
		}
		student getstu(){
			return stu;
		}
		void show(){
        cout<<"----------------------------"<<endl;
        cout<<"学号:"<<stu.id<<endl;
        cout<<"姓名:"<<stu.name<<endl;
        cout<<"性别:"<<stu.sex<<endl;
        cout<<"家庭住址:"<<stu.home<<endl;
        cout<<"联系电话:"<<stu.tele<<endl;
        cout<<"语文成绩:"<<stu.chinese<<endl;
        cout<<"数学成绩:"<<stu.math<<endl;
        cout<<"英语成绩:"<<stu.english<<endl;
        cout<<"平均成绩:"<<stu.aver<<endl;
        cout<<"考试名次:"<<stu.level<<endl;
        cout<<"同伴互评:"<<stu.clmate<<endl;
        cout<<"品德成绩:"<<stu.moral<<endl;
        cout<<"老师评分:"<<stu.techer<<endl;
        cout<<"综合成绩:"<<stu.last_score<<endl;
        cout<<"综合排名:"<<stu.last_level<<endl;
        cout<<"----------------------------"<<endl;
    }
};

Student *head;

Student *create(){
			int len;
			Student *head=new Student();
			if(head==NULL){
				cout<<"can't create.error!";
				return NULL;
			}
			Student *p=head;
			p->next=NULL;
			cout<<"输入要存储的学生数:";
			cin>>len;
			for(int i=0;i<len;i++){
				student stu;
				cout<<"输入第"<<i+1<<"个学生信息"<<endl;
				cout<<"学号:";
				cin>>stu.id;
				cout<<"姓名:";
				cin>>stu.name;
				cout<<"性别:";
				cin>>stu.sex;
				cout<<"家庭住址:";
				cin>>stu.home;
				cout<<"电话:";
				cin>>stu.tele;
				cout<<"语文成绩:";
				while(cin>>stu.chinese&&(stu.chinese<0||stu.chinese>100))
					cout<<"成绩只能在0-100,请重新输入\n";
				cout<<"数学成绩:";
				while(cin>>stu.math&&(stu.math<0||stu.math>100))
					cout<<"成绩只能在0-100,请重新输入\n";
				cout<<"英语成绩:";
				while(cin>>stu.english&&(stu.english<0||stu.english>100))
					cout<<"成绩只能在0-100,请重新输入\n";
				cout<<"同伴互评:";
				while(cin>>stu.clmate&&(stu.clmate<0||stu.clmate>100))
					cout<<"同伴互评只能在0-100,请重新输入\n";
				cout<<"品德成绩:";
				while(cin>>stu.moral&&(stu.moral<0||stu.moral>100))
					cout<<"品德成绩只能在0-100,请重新输入\n";
				cout<<"任课教师评分:";
				while(cin>>stu.techer&&(stu.techer<0||stu.techer>100))
					cout<<"教室评分只能在0-100,请重新输入\n";
				Student *q=new Student();
       			if(q==NULL){
           			cout<<"发生错误\n";
           			exit(0);
    			}
        		q->setstu(stu);
       			p->next=q;
        		q->next=NULL;
        		p=q;
   			}
    return head;
}

int lengthlist(Student *Head){
    int len=0;
    Student *temp=Head->next;
    while(temp){
        len++;
        temp=temp->next;
    }
    return len;
}

Student *sortlist(Student *Head)
{
    Student *p,*q;
    student temp;
    int i,j,level;
    int len=lengthlist(Head);
    for(i=0,p=Head->next;i<len;i++,p=p->next){
    	level=1;
        for(j=0,q=Head->next;j<len;j++,q=q->next){
           if(q->stu.aver>p->stu.aver){
               level++;
           }
        }
            p->stu.level=level;
    }

	for(i=0,p=Head->next;i<len;i++,p=p->next){
		level=1;
        for(j=0,q=Head->next;j<len;j++,q=q->next){
           if(q->stu.last_score>p->stu.last_score){
               level++;
           }
        }
            p->stu.last_level=level;
    }
    return Head;
}

void showlist(Student *Head)
{
    int i=1;
    Student *temp=Head->next;
    while(temp!=NULL)
    {
        cout<<endl<<"序号:"<<i<<endl;
        temp->show();
        temp=temp->next;
        i++;
    }
}   

void outfile()
{
    ofstream out;
   	out.open("xsxx.txt",ios_base::out|ios_base::app|ios_base::binary);
    if(!out){
        cout<<"文件不存在"<<endl;
        out.close();
    }
    else{  
        out.close();
       out.open("xsxx.txt",ios_base::out|ios_base::app|ios_base::binary);
    }
    Student *temp=head->next;
    while(temp!=NULL){
        student stu=temp->getstu();
        out.write(reinterpret_cast<char *>(&stu),sizeof(stu));
        temp=temp->next;
    }   
    out.close();
}

Student *infile()
{
    Student *head=new Student();
    if(NULL==head){
        cout<<"失败\n"<<endl;
        exit(0);
    }
    Student *p=head;
    p->next=NULL;
    ifstream in("xsxx.txt", ios::in | ios::binary);
    if (!in.is_open()){
        cout<<"打开失败\n"<<endl; 
        exit(0);
    }
    while (!in.eof()){
        student stu;
        in.read(reinterpret_cast<char *>(&stu),sizeof(stu));
        if (in.fail()) 
           break;
        Student *q=new Student();
        if(NULL==q){
           printf("失败\n");
           exit(0);
        }
        q->setst(stu);
        p->next=q;
        q->next=NULL;
        p=q;
    }
    in.close();
    return head;
}

Student *deletelist(Student *Head,int position,student *st)
{
    int i=0;
    Student *p=Head;
    while(NULL!=p->next&&i<position-1)
    {
        p=p->next;
        i++;
    }
    Student *q=p->next;
    *st=q->getstu();
    p->next=p->next->next;
    delete(q);
    q=NULL;
    return Head;
}

Student *editlist(Student *Head,int position,student *stu){
    int i=0;
    Student *p=Head;
    while(NULL!=p->next&&i<position-1){
    	p=p->next;
		i++;
	}
	if(NULL==p->next){
		cout<<"修改失败";
		return 0;
	}
    	Student *q=new Student();
    	cout<<"学号:";
		cin>>stu->id;
		cout<<"姓名:";
		cin>>stu->name;
		cout<<"性别:";
		cin>>stu->sex;
		cout<<"家庭住址:";
		cin>>stu->home;
		cout<<"电话:";
		cin>>stu->tele;
		cout<<"语文成绩:";
		while(cin>>stu->chinese&&(stu->chinese<0||stu->chinese>100))
			cout<<"成绩只能在0-100,请重新输入\n";
		cout<<"数学成绩:";
		while(cin>>stu->math&&(stu->math<0||stu->math>100))
			cout<<"成绩只能在0-100,请重新输入\n";
		cout<<"英语成绩:";
		while(cin>>stu->english&&(stu->english<0||stu->english>100))
			cout<<"成绩只能在0-100,请重新输入\n";
		cout<<"同伴互评:";
		while(cin>>stu->clmate&&(stu->clmate<0||stu->clmate>100))
			cout<<"同伴互评只能在0-100,请重新输入\n";
		cout<<"品德成绩:";
		while(cin>>stu->moral&&(stu->moral<0||stu->moral>100))
			cout<<"品德成绩只能在0-100,请重新输入\n";
		cout<<"任课教师评分:";
		while(cin>>stu->techer&&(stu->techer<0||stu->techer>100))
			cout<<"教室评分只能在0-100,请重新输入\n";
		q->setstu(*stu);
		q->next=p->next->next;
		p->next->next=q;
 	return Head;
}

void choose();
void showmenu(){
			cout<<"--------欢迎进入学生综合测评系统--------\n\n";
			cout<<"          0.插入学生信息.\n";
			cout<<"          1.修改学生信息.\n";
			cout<<"          2.删除学生信息.\n";
			cout<<"          3.浏览学生信息.\n";
			cout<<"          4.退出系统.\n";
			choose();
};

void choose(){
			int cho;
			do{
			cin>>cho;
			switch(cho){
				case 0:head=create();outfile();break;
				case 1:{
						cout<<"输入要修改的学生编号\n";
						int n;
						student *stu=new student;
						cin>>n;
						ofstream out;
   						head=editlist(infile(),n,stu);
   						head=deletelist(head,n,stu);
   						out.open("xsxx.txt",ios_base::out|ios_base::trunc|ios_base::binary);
   						Student *temp=head->next;
   						while(temp!=NULL){
					        student stu=temp->getstu();
					        out.write(reinterpret_cast<char *>(&stu),sizeof(stu));
					        temp=temp->next;
					    }   
					    out.close();
				}break;
				case 2:{
						cout<<"请输出要删除的序号:";
						int n;
						student *stu=new student;
						cin>>n;
						head=infile();
						ofstream out;
   						out.open("xsxx.txt",ios_base::out|ios_base::trunc|ios_base::binary);
   						head=deletelist(head,n,stu);
   						Student *temp=head->next;
   						while(temp!=NULL){
					        student stu=temp->getstu();
					        out.write(reinterpret_cast<char *>(&stu),sizeof(stu));
					        temp=temp->next;
					    }   
					    out.close();
						break;}
				case 3:showlist(sortlist(infile()));;break;
				case 4:break;
				default:cout<<"输入不符合要求\n";
		}
		}
		while(cho!=4);
}

main(){
	showmenu();
}
