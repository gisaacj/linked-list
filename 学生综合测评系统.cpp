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
        cout<<"ѧ��:"<<stu.id<<endl;
        cout<<"����:"<<stu.name<<endl;
        cout<<"�Ա�:"<<stu.sex<<endl;
        cout<<"��ͥסַ:"<<stu.home<<endl;
        cout<<"��ϵ�绰:"<<stu.tele<<endl;
        cout<<"���ĳɼ�:"<<stu.chinese<<endl;
        cout<<"��ѧ�ɼ�:"<<stu.math<<endl;
        cout<<"Ӣ��ɼ�:"<<stu.english<<endl;
        cout<<"ƽ���ɼ�:"<<stu.aver<<endl;
        cout<<"��������:"<<stu.level<<endl;
        cout<<"ͬ�黥��:"<<stu.clmate<<endl;
        cout<<"Ʒ�³ɼ�:"<<stu.moral<<endl;
        cout<<"��ʦ����:"<<stu.techer<<endl;
        cout<<"�ۺϳɼ�:"<<stu.last_score<<endl;
        cout<<"�ۺ�����:"<<stu.last_level<<endl;
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
			cout<<"����Ҫ�洢��ѧ����:";
			cin>>len;
			for(int i=0;i<len;i++){
				student stu;
				cout<<"�����"<<i+1<<"��ѧ����Ϣ"<<endl;
				cout<<"ѧ��:";
				cin>>stu.id;
				cout<<"����:";
				cin>>stu.name;
				cout<<"�Ա�:";
				cin>>stu.sex;
				cout<<"��ͥסַ:";
				cin>>stu.home;
				cout<<"�绰:";
				cin>>stu.tele;
				cout<<"���ĳɼ�:";
				while(cin>>stu.chinese&&(stu.chinese<0||stu.chinese>100))
					cout<<"�ɼ�ֻ����0-100,����������\n";
				cout<<"��ѧ�ɼ�:";
				while(cin>>stu.math&&(stu.math<0||stu.math>100))
					cout<<"�ɼ�ֻ����0-100,����������\n";
				cout<<"Ӣ��ɼ�:";
				while(cin>>stu.english&&(stu.english<0||stu.english>100))
					cout<<"�ɼ�ֻ����0-100,����������\n";
				cout<<"ͬ�黥��:";
				while(cin>>stu.clmate&&(stu.clmate<0||stu.clmate>100))
					cout<<"ͬ�黥��ֻ����0-100,����������\n";
				cout<<"Ʒ�³ɼ�:";
				while(cin>>stu.moral&&(stu.moral<0||stu.moral>100))
					cout<<"Ʒ�³ɼ�ֻ����0-100,����������\n";
				cout<<"�ον�ʦ����:";
				while(cin>>stu.techer&&(stu.techer<0||stu.techer>100))
					cout<<"��������ֻ����0-100,����������\n";
				Student *q=new Student();
       			if(q==NULL){
           			cout<<"��������\n";
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
        cout<<endl<<"���:"<<i<<endl;
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
        cout<<"�ļ�������"<<endl;
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
        cout<<"ʧ��\n"<<endl;
        exit(0);
    }
    Student *p=head;
    p->next=NULL;
    ifstream in("xsxx.txt", ios::in | ios::binary);
    if (!in.is_open()){
        cout<<"��ʧ��\n"<<endl; 
        exit(0);
    }
    while (!in.eof()){
        student stu;
        in.read(reinterpret_cast<char *>(&stu),sizeof(stu));
        if (in.fail()) 
           break;
        Student *q=new Student();
        if(NULL==q){
           printf("ʧ��\n");
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
		cout<<"�޸�ʧ��";
		return 0;
	}
    	Student *q=new Student();
    	cout<<"ѧ��:";
		cin>>stu->id;
		cout<<"����:";
		cin>>stu->name;
		cout<<"�Ա�:";
		cin>>stu->sex;
		cout<<"��ͥסַ:";
		cin>>stu->home;
		cout<<"�绰:";
		cin>>stu->tele;
		cout<<"���ĳɼ�:";
		while(cin>>stu->chinese&&(stu->chinese<0||stu->chinese>100))
			cout<<"�ɼ�ֻ����0-100,����������\n";
		cout<<"��ѧ�ɼ�:";
		while(cin>>stu->math&&(stu->math<0||stu->math>100))
			cout<<"�ɼ�ֻ����0-100,����������\n";
		cout<<"Ӣ��ɼ�:";
		while(cin>>stu->english&&(stu->english<0||stu->english>100))
			cout<<"�ɼ�ֻ����0-100,����������\n";
		cout<<"ͬ�黥��:";
		while(cin>>stu->clmate&&(stu->clmate<0||stu->clmate>100))
			cout<<"ͬ�黥��ֻ����0-100,����������\n";
		cout<<"Ʒ�³ɼ�:";
		while(cin>>stu->moral&&(stu->moral<0||stu->moral>100))
			cout<<"Ʒ�³ɼ�ֻ����0-100,����������\n";
		cout<<"�ον�ʦ����:";
		while(cin>>stu->techer&&(stu->techer<0||stu->techer>100))
			cout<<"��������ֻ����0-100,����������\n";
		q->setstu(*stu);
		q->next=p->next->next;
		p->next->next=q;
 	return Head;
}

void choose();
void showmenu(){
			cout<<"--------��ӭ����ѧ���ۺϲ���ϵͳ--------\n\n";
			cout<<"          0.����ѧ����Ϣ.\n";
			cout<<"          1.�޸�ѧ����Ϣ.\n";
			cout<<"          2.ɾ��ѧ����Ϣ.\n";
			cout<<"          3.���ѧ����Ϣ.\n";
			cout<<"          4.�˳�ϵͳ.\n";
			choose();
};

void choose(){
			int cho;
			do{
			cin>>cho;
			switch(cho){
				case 0:head=create();outfile();break;
				case 1:{
						cout<<"����Ҫ�޸ĵ�ѧ�����\n";
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
						cout<<"�����Ҫɾ�������:";
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
				default:cout<<"���벻����Ҫ��\n";
		}
		}
		while(cho!=4);
}

main(){
	showmenu();
}
