import sys
sys.path.append("..\..\..\AppData\Local\Programs\Python\Python310\Lib\site-packages")

from experta import *

class Greetings(KnowledgeEngine):

    def __init__(self, options_map, if_not_matched, get_courses, get_details):

        self.options_map = options_map
        self.if_not_matched = if_not_matched
        self.get_details = get_details
        self.get_courses = get_courses
        KnowledgeEngine.__init__(self)

    #code giving instructions on how to use the Expert System
    @DefFacts()
    def _initial_action(self):

        print("This is a knowledge based bot to guide people to their career paths.\n")
        print("Please tell me about your interests in the following.\n")
        print("Please reply in either yes or no.\n")
        yield Fact(action="find_path")

    #taking various input from user
    @Rule(Fact(action="find_path"), NOT(Fact(Career_in_management=W())), salience=1)
    def option_0(self):

        self.declare(Fact(Career_in_management=input("Do you want a career in management? : ")))

    @Rule(Fact(action="find_path"), NOT(Fact(IT_career=W())), salience=1)
    def option_1(self):

        self.declare(Fact(IT_career=input("Do you want a IT career? : ")))

    @Rule(Fact(action="find_path"), NOT(Fact(Research_oriented_career=W())), salience=1)
    def option_2(self):

        self.declare(Fact(Research_oriented_career=input("Do you want a research oriented career? : ")))

    #different rules checking for each path match
    @Rule(
        Fact(action="find_path"),
        Fact(Career_in_management="yes"),
        Fact(IT_career="no"),
        Fact(Research_oriented_career="no"),
    )
    def path_0(self):

        self.declare(Fact(path="Career in management"))

    @Rule(
        Fact(action="find_path"),
        Fact(Career_in_management="no"),
        Fact(IT_career="yes"),
        Fact(Research_oriented_career="no"),
    )
    def path_1(self):

        self.declare(Fact(path="IT career"))

    @Rule(
        Fact(action="find_path"),
        Fact(Career_in_management="no"),
        Fact(IT_career="no"),
        Fact(Research_oriented_career="yes"),
    )
    def path_2(self):

        self.declare(Fact(path="Research oriented career"))

    #when the user's input doesn't match any path in the knowledge base
    @Rule(Fact(action="find_path"), Fact(path=MATCH.path), salience=-998)
    def path(self, path):

        id_path = path
        path_details = self.get_details(id_path)
        treatments = self.get_courses(id_path)
        print("\nYour choosen career path is %s.\n" % (id_path))
        print("A short description of the career path is given below : \n")
        print(path_details + "\n")
        print("Some advice to succeed in it is as follows : \n")
        print(treatments + "\n")

    @Rule(
        Fact(action="find_path"),
        Fact(Career_in_management=MATCH.Career_in_management),
        Fact(IT_career=MATCH.IT_career),
        Fact(Research_oriented_career=MATCH.Research_oriented_career),
        NOT(Fact(path=MATCH.path)),
        salience=-999
    )
    def not_matched(self, Career_in_management, IT_career, Research_oriented_career,):
        
        print("\nThe bot did not find any career path that matches your exact interests.")