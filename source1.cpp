#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
#include<list>
#include<unordered_map>
using namespace std;
class Info
{
public:
	void print() {
		cout << ID << " " << Time<<endl;
	}
	Info() {
		ID = "";
		Time = 0;
	}
	Info(string id, int t) {
		ID = id;
		Time = t;
	}
	~Info() {}

public:
	string ID;
	int Time;
};

class MinHeap
{
public:

	void ReturnArrAndMap(Info*& t,unordered_map<string,int>&Map) {
		t = new Info[size - 1];
		for (int i = 1; i < size; i++)
		{
			t[i - 1] = arr[i];
		}
		Map = IndexMap;
	}
	void addIndexMap(unordered_map<string,int>Map) {
		IndexMap = Map;
	}
	MinHeap(int capacity) {
		if (capacity > 0) {
			size = capacity;
			arr = new Info[capacity];
		}
	}
	void insert(int TIME, string ID) {
		Info item(ID,TIME);
		if (currentCount >= size - 1) {
			int Newsize = size * 2;
			Info* NewArr = new Info[Newsize];
			int i = 0;
			while (i < size) {
				NewArr[i] = arr[i];
				i++;
			}
			// currentCount = i - 1;
			size = Newsize;
			delete[] arr;
			arr = NewArr;
		}
		arr[++currentCount] = item;
		for (int i = currentCount; (i / 2) > 0 && arr[i / 2].Time > arr[i].Time; i = i / 2)
		{
			swap(arr[i / 2], arr[i]);
		}

	}
	Info getMin() {
		if (currentCount > 0) {
			return arr[1];
		}

	}
	void DeleteMin() {
		swap(IndexMap[arr[1].ID], IndexMap[arr[currentCount].ID]);
		swap(arr[1], arr[currentCount--]);
		Heapify(1);
	}
	void DecreaseTime(string id, int NewTime)
	{
		int i = IndexMap[id];
		arr[i].Time = NewTime;
		int ind = i;
		for (int i = ind; i / 2 > 0 && arr[i / 2].Time > arr[i].Time; i = i / 2)
		{
			swap(IndexMap[arr[i].ID],IndexMap[arr[i/2].ID]);
			swap(arr[i / 2], arr[i]);
			
		}

	}
	bool is_Empty() {
		if (currentCount == 0)
			return 1;
		return 0;
	}
	void Heapify(int i) {
		if (i < currentCount) {

			int l = 2 * i;
			int r = 2 * i + 1;
			int min = i;
			if (l <= currentCount && arr[l].Time < arr[min].Time)
				min = l;
			if (r <= currentCount && arr[r].Time < arr[min].Time)
				min = r;
			if (min != i) {
				swap(IndexMap[arr[min].ID], IndexMap[arr[i].ID]);
				swap(arr[min], arr[i]);
				Heapify(min);
			}

		}
	}
	MinHeap() {
		arr = 0;
		size = 0;
		currentCount = 0;
	}
	~MinHeap() {
		if (arr)
			delete[] arr;
	}
	
	void print() {
		for (int i = 1; i <= currentCount; i++)
		{
			 arr[i].print();
		}
	}
	Info ReturnAtIndex(string id) {
		int index = IndexMap[id];
		return arr[index];
	}
private:
	Info* arr;
	int size;
	int currentCount;
	unordered_map<string, int> IndexMap;
};




void ReadData(string filename, vector<list<Info>>& Data) {
	ifstream read(filename);
	if (!read) {
		throw exception("Could'nt Found any File With this Name!");
	}
	else {
		int size = 0;
		read >> size;
		size++;
		read.ignore(numeric_limits<streamsize>::max(), '\n');
		for (int i = 0; i < size; i++)
		{
			string line;
			getline(read, line);
			stringstream ss(line);
			vector<string> WordsInaLine;
			while (getline(ss, line, ' '))
			{
				WordsInaLine.push_back(line);
			}
			vector<string>::iterator itr = WordsInaLine.begin();
			WordsInaLine.erase(itr);
			list<Info> TempList;
			for (int j = 0; j < WordsInaLine.size(); j++)
			{
				string id = WordsInaLine[j].substr(1, 2);
				WordsInaLine[j].erase(0, 4);
				WordsInaLine[j].pop_back();
				int time = stoi(WordsInaLine[j]);
				Info obj(id, time);
				// cout << id << " " << time << endl;
				TempList.push_back(obj);
			}
			Data.push_back(TempList);
		}
	}


}
void PrintData(vector<list<Info>>& data) {
	for (int i = 0; i < data.size(); i++)
	{
		cout << i;
		for (list<Info>::iterator itr = data[i].begin(); itr != data[i].end(); itr++)
		{
			cout << " ";
			// cout << (*itr);
			cout << " ";
		}
		cout << endl;
	}
}
void print(vector<int> p,Info* t,unordered_map<string,int>&IndexMap, int current) {
	if (current == -1)
		return;
	print(p,t,IndexMap, p[current]);
	if (current == 0)
	{
		cout << " UN" <<  " ->";
	}
	else {
		string id = "H";
		char ID_No = char(current) + 48;
		id.push_back(ID_No);
		int index = IndexMap[id];

	cout << " H" << current<<"("<< t[index-1].Time << ")" << " ->";

	}
}

void FindShortestDistance(vector<list<Info>>& Locations) {
	
	int size = Locations.size();
	MinHeap PQ(Locations.size());
	unordered_map<string, int> IndexMap;
		Info UN("00", 0);
		PQ.insert(0,"U0");
		pair<string, int> p1("U0",1);
		IndexMap.insert(p1);
		for (int i = 0; i < size-1; i++)
		{	
			string id = "H";
			char ID_No = char(i + 1)+48;

			id.push_back(ID_No);
			PQ.insert(INT_MAX, id);
			pair<string, int> p(id, i + 1+1);
			IndexMap.insert(p);
		}
		//PQ.print();
		PQ.addIndexMap(IndexMap);
		//vector<int> t(Locations.size(), INT_MAX);
		//t[0] = 0;
		vector<int> p(Locations.size(), -1);
		
	

		while (!PQ.is_Empty()) {


			Info u = PQ.getMin();
			int index = int(u.ID[1]) - 48;
			PQ.DeleteMin();
			for (list<Info>::iterator i = Locations[index].begin(); i != Locations[index].end(); i++)
			{
				string v = (*i).ID;
				int v1 = int((*i).ID[1])-48;
				if (u.Time + (*i).Time <= PQ.ReturnAtIndex(v).Time) {
					PQ.DecreaseTime(v, u.Time + (*i).Time);
					p[v1] = index;
				}
			}

			}
		cout << "\n\n\n";
		//PQ.print();
		Info* t;
		PQ.ReturnArrAndMap(t, IndexMap);
			 
			for (int i = 1; i < Locations.size(); ++i) {
				string id = "H";
				char ID_No = char(i) + 48;
				id.push_back(ID_No);
				int index = IndexMap[id];

				cout << "Optimal time to reach Hospital " << i << ": " << t[index-1].Time << " Minutes" << endl;

				cout << "Optimal path is: ";
				int current = i;

			
				print(p,t,IndexMap, current);
				cout << endl << endl;
			}
			int TTime = 0;
			for (int i = 0; i < size; i++)
			{
				TTime += t[i].Time;
			}
			cout << "Total Time To reach each Hospital: " << TTime;

			if (t);
			delete[] t;
		}

int main() 
{
	vector<list<Info>> data;
	string FileName;
	cout << "Enter File Name: ";
	cin >> FileName;
	try {
	ReadData(FileName, data);
	}
	catch(exception ex) {
		cout<<ex.what();
	}
	FindShortestDistance(data);
}
