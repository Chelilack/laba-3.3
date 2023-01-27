#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include "ArraySequenceTests.h"
#include "DynamicArrayTests.h"
#include "LinkedListTests.h"
#include "LinkedListSequenceTests.h"
#include"ArraySequence.h"
#include"LinkedListSequence.h"
#include "Sequence.h"
#include "ComplexNumber.h"
#include "Student.h"
#include "Teacher.h"
#include "Errors.h"
#include "Input.h"
#include "graph.h"
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
extern int ID = 1;
void menu() 
{
	int* forForexample = new int[]{ 1,4,6,7,4,2,4 };
	Sequence<int>* forExample = new ArraySequence<int>(forForexample,7);
	Graph<int>* graph =0;
	int page = 1;
	int minipage = -1;
	while (page != 0)
	{
		system("cls");
		if (page == 1)
		{
			cout << "-------------------------------------------" << endl;
			cout << "|0. Exit                                  |" << endl;
			cout << "|1. Create graph                          |" << endl;
			cout << "|2. Create weighted graph                 |" << endl;
			cout << "|3. Create directed graph                 |" << endl;
			cout << "|4. Create directed weighted graph        |" << endl;
			cout << "-------------------------------------------" << endl;
			cin >> minipage;
			while (minipage != 1 && minipage != 2 && minipage != 3 && minipage != 4 && minipage != 0)
			{
				cout << "try again!" << endl;
				cin >> minipage;
			}
		}
		if (minipage == 0) 
		{
			page = 0;
		}
		if(page==1)
		{
			int inputType;
			cout << "--------------------" << endl;
			cout << "|1. Input          |" << endl;
			cout << "|2. Random Input   |" << endl;
			cout << "--------------------" << endl;
			cin >> inputType;
			while (inputType != 1 && inputType != 2)
			{
				cout << "try again!" << endl;
				cin >> inputType;
			}
			int countVertex;
			int countConnectedVertex;
			cout << "Enter count of vertex:" << endl;
			cin >> countVertex;
			Sequence<InfoVertex<int>>* pair;
			Sequence<InfoVertexWeight<int>>* pairWeight;
			if (inputType == 1)
			{
				switch (minipage)
				{
				case 1:
					pair = new ArraySequence<InfoVertex<int>>();
					for (int i = 0; i < countVertex; i++)
					{
						InfoVertex<int> pass;
						pass.connectedVerts = new ArraySequence<int>();
						cout << "Enter value:" << endl;
						cin >> pass.value;
						cout << "Enter count of connected Vertex" << endl;
						cin >> countConnectedVertex;

						for (int j = 0; j < countConnectedVertex; j++)
						{
							int pass2;
							cout << "Enter " << j + 1 << " of " << countConnectedVertex << " value:" << endl;
							cin >> pass2;
							pass.connectedVerts->Append(pass2);
						}
						pair->Append(pass);
						cout << "------------------" << endl;
					}
					graph = new Graph<int>(pair, 0);
					break;
				case 2:
					pairWeight = new ArraySequence<InfoVertexWeight<int>>();
					for (int i = 0; i < countVertex; i++)
					{
						InfoVertexWeight<int> pass;
						pass.connectedVerts = new ArraySequence<ConnectedVerts<int>>();
						cout << "Enter value:" << endl;
						cin >> pass.value;
						cout << "Enter count of connected Vertex" << endl;
						cin >> countConnectedVertex;

						for (int j = 0; j < countConnectedVertex; j++)
						{
							ConnectedVerts<int> pass2;
							cout << "Enter " << j + 1 << " of " << countConnectedVertex << " value:" << endl;
							cin >> pass2.value;
							cout << "Enter " << j + 1 << " of " << countConnectedVertex << " weight:" << endl;
							cin >> pass2.weight;
							pass.connectedVerts->Append(pass2);
						}
						pairWeight->Append(pass);
						cout << "------------------" << endl;
					}
					graph = new Graph<int>(pairWeight, 0);
					break;
				case 3:
					pair = new ArraySequence<InfoVertex<int>>();
					for (int i = 0; i < countVertex; i++)
					{
						InfoVertex<int> pass;
						pass.connectedVerts = new ArraySequence<int>();
						cout << "Enter value:" << endl;
						cin >> pass.value;
						cout << "Enter count of connected Vertex" << endl;
						cin >> countConnectedVertex;

						for (int j = 0; j < countConnectedVertex; j++)
						{
							int pass2;
							cout << "Enter " << j + 1 << " of " << countConnectedVertex << " value:" << endl;
							cin >> pass2;
							pass.connectedVerts->Append(pass2);
						}
						pair->Append(pass);
						cout << "------------------" << endl;
					}
					graph = new Graph<int>(pair, 1);
					break;
				case 4:
					pairWeight = new ArraySequence<InfoVertexWeight<int>>();
					for (int i = 0; i < countVertex; i++)
					{
						InfoVertexWeight<int> pass;
						pass.connectedVerts = new ArraySequence<ConnectedVerts<int>>();
						cout << "Enter value:" << endl;
						cin >> pass.value;
						cout << "Enter count of connected Vertex" << endl;
						cin >> countConnectedVertex;

						for (int j = 0; j < countConnectedVertex; j++)
						{
							ConnectedVerts<int> pass2;
							cout << "Enter " << j + 1 << " of " << countConnectedVertex << " value:" << endl;
							cin >> pass2.value;
							cout << "Enter " << j + 1 << " of " << countConnectedVertex << " weight:" << endl;
							cin >> pass2.weight;
							pass.connectedVerts->Append(pass2);
						}
						pairWeight->Append(pass);
						cout << "------------------" << endl;
					}
					graph = new Graph<int>(pairWeight, 1);
					break;
				}
			}
			else
			{
				int maxValue;
				int maxWeight=0;
				cout << "Enter max value:" << endl;
				cin >> maxValue;
				int* vertexes = 0;
				switch (minipage)
				{
				case 1:

					pair = new ArraySequence<InfoVertex<int>>();
					vertexes = new int[countVertex];
					
					for (int i = 0; i < countVertex; i++) 
					{
						vertexes[i] = rand() % maxValue + 1;
					}
					for (int i = 0; i < countVertex; i++)
					{
						InfoVertex<int> pass;
						pass.connectedVerts = new ArraySequence<int>();
						pass.value = vertexes[i];
						countConnectedVertex = rand() % (countVertex+1);

						for (int j = 0; j < countConnectedVertex; j++)
						{
							pass.connectedVerts->Append(vertexes[rand()%countVertex]);
						}
						pair->Append(pass);
					}
					graph = new Graph<int>(pair, 0);
					break;
				case 2:
					pairWeight = new ArraySequence<InfoVertexWeight<int>>();
					vertexes = new int[countVertex];
					cout << "Enter max weight:" << endl;
					cin >> maxWeight;

					for (int i = 0; i < countVertex; i++)
					{
						vertexes[i] = rand() % maxValue + 1;
					}
					for (int i = 0; i < countVertex; i++)
					{
						InfoVertexWeight<int> pass;
						pass.value = rand() % maxValue + 1;
						pass.connectedVerts = new ArraySequence<ConnectedVerts<int>>();
						countConnectedVertex = rand() % (countVertex+1);

						for (int j = 0; j < countConnectedVertex; j++)
						{
							ConnectedVerts<int> pass2;
							pass2.value= vertexes[j];
							pass2.weight= rand() % (maxWeight + 1);
							pass.connectedVerts->Append(pass2);
						}
						pairWeight->Append(pass);
					}
					graph = new Graph<int>(pairWeight, 0);
					break;
				case 3:
					pair = new ArraySequence<InfoVertex<int>>();
					vertexes = new int[countVertex];

					for (int i = 0; i < countVertex; i++)
					{
						vertexes[i] = rand() % maxValue + 1;
					}
					for (int i = 0; i < countVertex; i++)
					{
						InfoVertex<int> pass;
						pass.connectedVerts = new ArraySequence<int>();
						pass.value = vertexes[i];
						countConnectedVertex = rand() % (countVertex + 1);

						for (int j = 0; j < countConnectedVertex; j++)
						{
							pass.connectedVerts->Append(vertexes[rand() % countVertex]);
						}
						pair->Append(pass);
					}
					graph = new Graph<int>(pair, 1);
					break;
				case 4:
					pairWeight = new ArraySequence<InfoVertexWeight<int>>();
					vertexes = new int[countVertex];
					cout << "Enter max weight:" << endl;
					cin >> maxWeight;

					for (int i = 0; i < countVertex; i++)
					{
						vertexes[i] = rand() % maxValue + 1;
					}
					for (int i = 0; i < countVertex; i++)
					{
						InfoVertexWeight<int> pass;
						pass.value = rand() % maxValue + 1;
						pass.connectedVerts = new ArraySequence<ConnectedVerts<int>>();
						countConnectedVertex = rand() % (countVertex + 1);

						for (int j = 0; j < countConnectedVertex; j++)
						{
							ConnectedVerts<int> pass2;
							pass2.value = vertexes[j];
							pass2.weight = rand() % (maxWeight + 1);
							pass.connectedVerts->Append(pass2);
						}
						pairWeight->Append(pass);
					}
					graph = new Graph<int>(pairWeight, 1);
					break;


				}
			}
			page = 2;
		}
		if (page == 2) 
		{
			int minipage2;
			cout << "---------------------------------" << endl;
		    cout << "|0. Exit                        |" << endl;
			cout << "|1. Add vertex                  |" << endl;
			cout << "|2. Delete vertex               |" << endl;
			cout << "|3. Add edge                    |" << endl;
			cout << "|4. Delete edge                 |" << endl;
			cout << "|5. Print out                   |" << endl;
			cout << "|6. Kommivoiger task            |" << endl;
			cout << "|7. Run unit tests              |" << endl;
			cout << "---------------------------------" << endl;
			cin>>minipage2;
			int countConnectedForAdd=0;
			int valueForAdd=0;
			int valueForDelete =0;
			int startValueForAdd, destinationValueForAdd, weightForAdd;
			int startValueForDelete, destinationValueForDelete;
			vector<Vertex<int>*> vertexForTask;
			int minPath = 10000000;
			switch (minipage2) 
			{

			case 0:
				page = 0;
				break;
			case 1:
				cout << "Enter value:" << endl;
				cin >> valueForAdd;
				cout << "Enter count of connected Vertex :" << endl;
				cin >> countConnectedForAdd;
				if (!graph->IsWeighted()) {
					Sequence<int>* seq = new ArraySequence<int>();
					for (int i = 0; i < countConnectedForAdd; i++) {
						int connected;
						cout << "Enter " << i+ 1 << " of " << countConnectedForAdd << " value:" << endl;
						cin >> connected;
						seq->Append(connected);
					}
					graph->AddVertex(valueForAdd, seq);
				}
				else {
					InfoVertexWeight<int> pass;
					pass.connectedVerts = new ArraySequence<ConnectedVerts<int>>();
					pass.value = valueForAdd;

					for (int j = 0; j < countConnectedForAdd; j++)
					{
						ConnectedVerts<int> pass2;
						cout << "Enter " << j + 1 << " of " << countConnectedForAdd << " value:" << endl;
						cin >> pass2.value;
						cout << "Enter " << j + 1 << " of " << countConnectedForAdd << " weight:" << endl;
						cin >> pass2.weight;
						pass.connectedVerts->Append(pass2);
					}
					graph->AddVertexWeighted(pass.value,pass.connectedVerts);
				}
				break;
			case 2:
				
				cout << "Enter value:" << endl;
				cin >> valueForDelete;
				graph->DeleteVertex(valueForDelete);
				break;
			case 3:
				cout << "Enter start vertex:" << endl;
				cin >> startValueForAdd;
				cout << "Enter destination vertex:" << endl;
				cin >> destinationValueForAdd;
				cout << "edge weight or 0:" << endl;
				cin >> weightForAdd;
				graph->AddEdge(startValueForAdd, destinationValueForAdd, weightForAdd);
				break;
			case 4:
				cout << "Enter start vertex:" << endl;
				cin >> startValueForDelete;
				cout << "Enter destination vertex:" << endl;
				cin >> destinationValueForDelete;
				graph->DeleteEdge(startValueForDelete, destinationValueForDelete);
				break;
			case 5:
				graph->PrintOut();
				break;
			case 6:
				
				/*for (int i = 0; i < graph->GetVertexes()->GetLength(); i++)
					vertexForTask.Append(graph->GetVertexes()->Get(i));
				minPath = 10000000;
				do {
					int currentPathWeight = 0;
					for (int i = 0; i < vertexForTask.GetLength() - 1; i++) {
						for (int j = 0; j < vertexForTask.Get(i)->GetEdges()->GetLength(); j++) 
						{
							if (vertexForTask.Get(i)->GetEdges()->Get(j).GetStart() == vertexForTask.Get(i + 1))
							{
								currentPathWeight += vertexForTask.Get(i)->GetEdges()->Get(j).GetWeight();
							}
						}
					}
					minPath = min(minPath, currentPathWeight);
					} 
				while (next_permutation(vertexForTask.GetFirst(),vertexForTask.GetLast()));
				*/
				for (int i = 0; i < graph->GetVertexes()->GetLength(); i++) 
				{
					vertexForTask.push_back(graph->GetVertexes()->Get(i));
				}
				minPath = 10000000;
				do
				{
					int currentPathWeight = 0;
					for (int i = 0; i < vertexForTask.size() - 1; i++) 
					{
						for (int j = 0; j < vertexForTask[i]->GetEdges()->GetLength(); j++) 
						{
							if (vertexForTask[i]->GetEdges()->Get(j).GetStart() == vertexForTask[i + 1]) 
							{
								currentPathWeight += vertexForTask[i]->GetEdges()->Get(j).GetWeight();
							}
						}
					}
					minPath = min(minPath, currentPathWeight);
				} while (
					next_permutation(vertexForTask.begin(), vertexForTask.end()));

				cout << "answer: " << minPath << endl;
				break;
			case 7:
				LinkedListTests * testList = new LinkedListTests();
				DynamicArrayTests* testArray = new DynamicArrayTests();
				LinkedListSequenceTests* testListSequence = new LinkedListSequenceTests();
				ArraySequenceTests* testArraySequence = new ArraySequenceTests();
				testArray->Test();
				std::this_thread::sleep_for(400ms);
				testList->Test();
				std::this_thread::sleep_for(400ms);
				testListSequence->Test();
				std::this_thread::sleep_for(400ms);
				testArraySequence->Test();
				std::this_thread::sleep_for(400ms);
				cout << "Laba work correctly\n";
				system("pause");
				page = -1;
				break;
			}
			system("pause");
		}

	}
}