import sys
sys.path.append("..\..\..\AppData\Local\Programs\Python\Python310\Lib\site-packages")

# Import libraries
from aima import utils
from aima import logic

import warnings
warnings.filterwarnings('ignore')

# The main entry point for this module
def main():

    # Create an array to hold clauses
    clauses = []

    # Add first-order logic clauses (rules and fact)
    clauses.append(utils.expr("(Honest(x) & Politician(x) & Promise(y) & GivesPromise(x,y)) ==> KeepsPromise(x,y)"))
    clauses.append(utils.expr("(Party(x) & Promise(y) & GivesPromise(x,y) & Person(z) & Leader(z,x)) ==> GivesPromise(z,y)"))
    clauses.append(utils.expr("(Person(x) & Promise(y) & KeepsPromise(x,y) & Party(z) & Leader(x,z)) ==> KeepsPromise(z,y)"))
    clauses.append(utils.expr("(Person(x) & Leader(x,y)) ==> Politician(x)"))
    clauses.append(utils.expr("Party(ABCD)"))
    clauses.append(utils.expr("Promise(P1)"))
    clauses.append(utils.expr("Person(XYZ)"))
    clauses.append(utils.expr("GivesPromise(ABCD,P1)"))
    # clauses.append(utils.expr("~(KeepsPromise(ABCD,P1))"))
    clauses.append(utils.expr("Leader(XYZ,ABCD)"))

    # Create a first-order logic knowledge base (KB) with clauses
    KB = logic.FolKB(clauses)

    # Add rules and facts with tell
    KB.tell(utils.expr('Politician(PQR)'))
    # KB.tell(utils.expr('~(KeepsPromise(ABCD,P1))'))

    # Get information from the knowledge base with ask via forward chaining
    politician = logic.fol_fc_ask(KB, utils.expr('Leader(x)'))

    # Get information from the knowledge base with ask via backward chaining
    # politician = KB.ask(utils.expr('Politician(x)'))

    # Print answers
    print('Leader?')
    print(list(politician))

    print()

# Tell python to run main method
if __name__ == "__main__": main()