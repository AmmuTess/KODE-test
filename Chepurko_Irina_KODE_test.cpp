#include <iostream>
#include <cstring>
#include <fstream>
#include<cmath>

#include <time.h>


using namespace std;

class DataSorter {
	//PUBLIC
	public:
		
		void set_name(string a){
			name=a;
		}
		void set_x(float k){
			x=k;
		}
		void set_y(float k){
			y=k;
		}
		void set_type(string a){
			type=a;
		}
		void set_time(double k){
			t=k;
		}
		
		void set_distance(float a,float b){
			distance=sqrt(pow(a,2)+pow(b,2));
		}
		void set_dist_fl (float a){
			distance=a;
		}
		
		void set_numb(int k){
			type_numb=k;
		}
				
		
		string get_name(){
			return name;
		}
		float get_x(){
			return x;
		}
		float get_y(){
			return y;
		}
		string get_type(){
			return type;
		}
		double get_time(){
			return t;
		}
		
		float get_distance(){
			return distance;
		}
		
		int get_numb(){
			return type_numb;
		}
		
		
		
	//PRIVATE	
	private:
		string name;
		float x,y,distance;
		string type;
		double t;
		int type_numb;
};

int main()
{
	setlocale (LC_ALL, "Rus");
	
	ifstream input;
	ofstream output;
	string o_name,o_type;
	float o_x,o_y;
	double T;
	
	//кол-во эл-тов в списке
    int size=0;
    input.open("input.txt");
    while (!input.eof())
    {
        getline(input,o_name,'\n');
        size++;
    }
    input.close();
	
	
	DataSorter obj[size], temp;
	
	input.open("input.txt");
	output.open("output.txt");
	
	output.setf(ios::fixed);
	
	
	if(input)
	{
		//считывание данных
		while(!input.eof())
		{		
			for(int i=0;i<size;i++)
			{			
				input>>o_name>>o_x>>o_y>>o_type>>T;
				obj[i].set_name(o_name);
				obj[i].set_x(o_x);
				obj[i].set_y(o_y);
				obj[i].set_type(o_type);
				obj[i].set_time(T);
						
				getline(input,o_name,'\n');
			}		
		input.close();
		}
		
		cout<<"Выберите вид группировки:"<<endl<<"1 - по расстоянию, 2- по имени, 3 - по типу, 4 - по времени"<<endl;
		int kind_of_group;
		cin>>kind_of_group;
		while(kind_of_group>4 || kind_of_group<1) 
			{
				cout<<"Неверное значение введите число от 1 до 4!"<<endl;
				cin>>kind_of_group;
			}
	//РАССТОЯНИЕ	
		if(kind_of_group==1)	
		{
				for(int i=0;i<size;i++)
				{
					obj[i].set_distance(obj[i].get_x(),obj[i].get_y());
					//cout<<i<<" | "<<obj[i].get_distance()<<endl;
				}
				
				//сортировка по расстоянию
				for(int i=1;i<size;i++)
		       		for(int j=i;j>0;j--)
		       		{    	
		       			o_x=obj[j].get_distance();
		       			o_y=obj[j-1].get_distance(); 
		       			
		          		if(o_x<o_y)
		          		{
							temp=obj[j];
							obj[j]=obj[j-1];
							obj[j-1]=temp;								
		          		}
	          		}
		 				
		 		//группировка по расстоянию
		 		bool up_100_un=false, up_1000_un=false, up_10000_un=false, too_far=false;
		 		
		 		output<<"Группировка по расстоянию"<<endl;
		 		for(int i=0;i<size;i++)
		 		{
		 			
				 	if(obj[i].get_distance()<=100)
				 	{
				 		if(!up_100_un)
				 		{
				 			output<<"До 100 ед."<<endl;
							output<<obj[i].get_distance()<<" | "<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
				 			up_100_un=true;
				 		}
				 		else
				 		output<<obj[i].get_distance()<<" | "<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
				 	}		 	
				 	else		 			 		
				 	if(obj[i].get_distance()<=1000)
				 	{
				 		if(!up_1000_un)
				 		{
				 			output<<"До 1000 ед."<<endl;
							output<<obj[i].get_distance()<<" | "<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
				 			up_1000_un=true;
				 		}
				 		else
				 		output<<obj[i].get_distance()<<" | "<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
				 	}		 		 		
				 	else
					if(obj[i].get_distance()<=10000)
				 	{
				 		if(!up_10000_un)
				 		{
				 			output<<"До 10000 ед."<<endl;
							output<<obj[i].get_distance()<<" | "<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
				 			up_10000_un=true;
				 		}
				 		else
				 		output<<obj[i].get_distance()<<" | "<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
				 	}	
					else				 
				 	{
				 		if(!too_far)
				 		{
				 			output<<"Слишком далеко"<<endl;
							output<<obj[i].get_distance()<<" | "<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
				 			too_far=true;
				 		}
				 		else
				 		output<<obj[i].get_distance()<<" | "<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
				 	}				 			
	 			}
		}
		else
		//ИМЯ	
		if(kind_of_group==2)	
		{	                     
		 		//сортировка по имени
				for(int i=1;i<size;i++)
		       		for(int j=i;j>0;j--)
		       		{     		
		          		if(obj[j].get_name()<obj[j-1].get_name())
		          		{					
							
							temp=obj[j];
							obj[j]=obj[j-1];
							obj[j-1]=temp;	
									       
						} 
	           	}  		
		
				//группирвка по имени
		 		output<<"Группировка по имени"<<endl;
		 		for(int i=0;i<size;i++)		
		 		{
		 			if(i==0 && ((obj[i].get_name()[0]<'А')||(obj[i].get_name()[0]>'Я')))
		 				output<<"#"<<endl;
		 			else
					if(i==0)
					 	output<<obj[i].get_name()[0]<<endl;
					else
					if(i>0 && obj[i].get_name()[0]!=obj[i-1].get_name()[0] && ((obj[i].get_name()[0]>'А')&&(obj[i].get_name()[0]<'Я')))
						output<<obj[i].get_name()[0]<<endl;
					
					output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
				
		 		}
		}
		else
		//ТИП	
		if(kind_of_group==3)	
		{			
		 		//сортировка по имени
				for(int i=1;i<size;i++)
		       		for(int j=i;j>0;j--)
		       		{     		
		          		if(obj[j].get_name()<obj[j-1].get_name())
		          		{					
							temp=obj[j];
							obj[j]=obj[j-1];
							obj[j-1]=temp;								       
						} 
	           	} 
	           	
				//счётчик типов
				for(int i=0;i<size;i++)
				{
					int k=1;
					obj[i].set_numb(k);	
					for(int j=0;j<i;j++)
					{
						if(obj[i].get_type()==obj[j].get_type())
						{
							k++;
							obj[i].set_numb(k);
							obj[j].set_numb(k);							
						}									
					}			
				}
				
				//группировка по типу
				output<<"Группировка по типу"<<endl;
				for(int i=0;i<size;i++)
				{
					if(obj[i].get_numb()>1)
					{
						output<<obj[i].get_type()<<endl;
						output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
						
						obj[i].set_numb(0);
						for(int j=i+1;j<size;j++)
						{
							if(obj[i].get_type()==obj[j].get_type())
							{
								output<<obj[j].get_name()<<" "<<obj[j].get_x()<<" "<<obj[j].get_y()<<" "<<obj[j].get_type()<<" "<<obj[j].get_time()<<endl;
								obj[j].set_numb(0);
							}			
						}
					}								
				}
				
				bool o=false;
				for(int i=0;i<size;i++)
				{
					
					if(obj[i].get_numb()==1)
						if(!o)
						{
							output<<"Разное"<<endl;
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
							o=true;
						}
						else
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
				}
			
		}
		else
		//ВРЕМЯ	
		if(kind_of_group==4)	
		{			
				//сортировка по времени
				for(int i=1;i<size;i++)
		       		for(int j=i;j>0;j--)
		       		{     		
		          		if(obj[j].get_time()>obj[j-1].get_time())
		          		{					
							temp=obj[j];
							obj[j]=obj[j-1];
							obj[j-1]=temp;								       
						} 
	           	} 	
	  
	  			//текущее время   	
				time_t current_time;
				time(&current_time);
				
				int hours, minutes, seconds, m_day, w_day, month, year;
				 
				struct tm *local = localtime(&current_time);
				 
				hours = local->tm_hour;
				minutes = local->tm_min; 
				seconds = local->tm_sec; 
				 
				m_day = local->tm_mday; 
				w_day = local->tm_wday;        
				month = local->tm_mon + 1;      
				year = local->tm_year + 1900;		    
				    
				time_t object_time;
				bool today=false, yesterday=false, this_week=false, this_month=false, this_year=false, earlier=false;
	
	           	//группировка по времени
	           	output<<"Группировка по времени"<<endl;			
				for(int i=0;i<size;i++)
				{
					int obj_hours, obj_minutes, obj_seconds, obj_m_day, obj_w_day, obj_month, obj_year;
					
					time_t object_time=obj[i].get_time();
					time_t time_diff=difftime(current_time, object_time);
				 
					struct tm *obj_local[size];
					obj_local[i] = localtime(&object_time);
					 
					obj_hours = obj_local[i]->tm_hour;
					obj_minutes = obj_local[i]->tm_min;
					obj_seconds = obj_local[i]->tm_sec;
					 
					obj_m_day = obj_local[i]->tm_mday;  
					obj_w_day = obj_local[i]->tm_wday; 
					obj_month = obj_local[i]->tm_mon + 1;  
					obj_year = obj_local[i]->tm_year + 1900;
													
					if(obj_year==year && obj_month==month && obj_m_day==m_day)
					{
						if(!today)
		           		{
		           			output<<"Сегодня:"<<endl;
		           			output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
		           			today=true;
		           		}
		           		else
		           		{
		           			output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;	           			
		           		}
	
					}
					else
					if(obj_year==year && obj_month==month && m_day-obj_m_day==1)
					{
						if(!yesterday)
		           		{
		           			output<<"Вчера:"<<endl;
							output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
		           			yesterday=true;
		           		}
		           		else
		           		{
		           			output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;	           				           			
		           		}
					}
					else
					if(obj_year==year && obj_month==month && m_day-obj_m_day<7 && w_day-obj_w_day>0)
					{
						if(!this_week)
		           		{
		           			output<<"На этой неделе:"<<endl;
							output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
		           			this_week=true;
		           		}
		           		else
		           		{
		           			output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;	           				           			
		           		}
					}					
					else
					if(obj_year==year && obj_month==month)
					{
						if(!this_month)
		           		{
		           			output<<"В этом месяце:"<<endl;
							output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
		           			this_month=true;
		           		}
		           		else
		           		{
		           			output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;	           				           			
		           		}
					}
					else
					if(obj_year==year)
					{
						if(!this_year)
		           		{
		           			output<<"В этом году:"<<endl;
							output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
		           			this_year=true;
		           		}
		           		else
		           		{
		           			output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;	           				           			
		           		}
					}
					else
					{
						if(!earlier)
		           		{
		           			output<<"Ранее:"<<endl;
							output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;
		           			earlier=true;
		           		}
		           		else
		           		{
		           			output<<"Время создания объекта: "<<ctime(&object_time);
							output<<obj[i].get_name()<<" "<<obj[i].get_x()<<" "<<obj[i].get_y()<<" "<<obj[i].get_type()<<" "<<obj[i].get_time()<<endl;	           				           			
		           		}
					}												
				}				 	
		}
	cout<<"Готово! Результат группировки в файле output.txt"<<endl;	
	}
	
	else cout<<"Файл не существует"<<endl;	
	
	return 0;
}
