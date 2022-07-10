from greetings import Greetings
careerpaths_list = []
careerpaths_options = []
options_map = {}
desc_map = {}
courses_map = {}

#loads the knowledge from .txt files into variables to allow the code to use it
def preprocess():

    global careerpaths_list, careerpaths_options, options_map, desc_map, courses_map
    options = open("options.txt")
    options_t = options.read()
    careerpaths_list = options_t.split("\n")
    options.close()

    for paths in careerpaths_list:

        path_file = open("Matching/" + paths + ".txt")
        path_data = path_file.read()
        s_list = path_data.split("\n")
        careerpaths_options.append(s_list)
        options_map[str(s_list)] = paths
        path_file.close()

        path_file = open("Description/" + paths + ".txt")
        path_data = path_file.read()
        desc_map[paths] = path_data
        path_file.close()

        path_file = open("Courses/" + paths + ".txt")
        path_data = path_file.read()
        courses_map[paths] = path_data
        path_file.close()


def identify_path(*arguments):

    options_list = []
    for option in arguments:

        options_list.append(option)

    return options_map[str(options_list)]

def get_details(path):

    return desc_map[path]

def get_courses(path):

    return courses_map[path]

def if_not_matched(path):

    id_path = path
    path_details = get_details(id_path)
    courses = get_courses(id_path)
    print("\nYour choosen career path is %s.\n" % (id_path))
    print("A short description of the career path is given below :\n")
    print(path_details + "\n")
    print("Some advice to succeed in it is as follows :\n")
    print(courses + "\n")

#driver function
if __name__ == "__main__":

    preprocess()
    #creating class object
    engine = Greetings(options_map, if_not_matched, get_courses, get_details)
    #loop to keep running the code until user says no when asked for another diagnosis
    while 1:
        engine.reset()
        engine.run()
        print("Would you like to ask for some more guidance?\nPlease reply in either yes or no.")
        if input() == "no":

            print("Thank you and have a nice day!")
            exit()