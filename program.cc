#include <iostream>
#include<string>
#include <vector> 
#include "ortools/base/logging.h"
#include "ortools/constraint_solver/constraint_solver.h"

using namespace std;

namespace operations_research {
void RunConstraintProgrammingExample() {
 
  Solver solver("N-QueenSolver");
  
  ///////////////////////////////////////////////////////////////////////////////////////////
  const int64 numVals = 4; // Enter Number Of Queens Here
  //////////////////////////////////////////////////////////////////////////////////////////

  std::vector<IntVar*> Queens;
  
  for(int i=0; i<numVals; i++)
  {
  	IntVar* x = solver.MakeIntVar(1, numVals, to_string(i));
  	Queens.push_back(x);
  }
   
  solver.AddConstraint(solver.MakeAllDifferent(Queens));	// alldifferent costraint for row attacks
  

  vector<IntVar*> vars(numVals);
  vector<IntVar*> vars2(numVals);
  for(int i=0; i<numVals; i++)
  { 
  	vars[i] = solver.MakeSum(Queens[i], i)->Var();
  	vars2[i] = solver.MakeSum(Queens[i], -i)->Var();
  }
  
  solver.AddConstraint(solver.MakeAllDifferent(vars));		// alldifferent constrints for diagonal attacks
  solver.AddConstraint(solver.MakeAllDifferent(vars2));


  DecisionBuilder* const db = solver.MakePhase(
      Queens, Solver::CHOOSE_FIRST_UNBOUND, Solver::ASSIGN_MIN_VALUE);

  solver.NewSearch(db);
  while (solver.NextSolution()){
    
    for (int i=0; i<numVals; i++)
    	cout<< "Row Of Queen " << to_string(i)<< " : " <<Queens.at(i) -> Value() <<"\n";
  	
  	for (int m=0; m<numVals; m++)
    	{
    		for (int n=0; n<numVals; n++)
    		{
    			if (Queens.at(m) -> Value() == n+1)
    				cout<< "X ";
    			else
    				cout<< ". ";
    		}
    		cout<<endl;
    	}	
  	
    	break;
  }
  solver.EndSearch();
  
}
}  


int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);
  FLAGS_logtostderr = 1;
  operations_research::RunConstraintProgrammingExample();
  return EXIT_SUCCESS;
}
