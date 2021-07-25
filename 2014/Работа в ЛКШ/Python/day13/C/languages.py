fin = open("languages.in", "r")
fout = open("languages.out", "w")
count_pupils = int(fin.readline())
languages = []
languages_set = {}
common_lenguage = 0
for i in range(count_pupils):
    for j in range(language_count):
        language = fin.readline().split()
        languages_set[i].add(language)
        languages.append(languages_set[i])

        
        
fout.close()