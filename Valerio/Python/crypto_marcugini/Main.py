from Cypher import Cypher
from AI_decypher import AI_decypher
from Alpha import Alpha
from Reader import Reader
import re

c = Cypher(file='fileTest.txt')
print(c.crypt())
#print(c.alpha)
ai = AI_decypher(string=c.crypt(), lang_dict_path='words.italian.txt', entropy_from=['discorso_conte.txt', 'biancaneve.txt'])
# print(ai.entropy_from_documents.sort('descending'))
# print(ai.entropy.sort('descending'))

split_file = list(map(lambda s: re.sub(r"\W",'', s).lower(), Reader.read('fileTest.txt').split()))
it_dict = Reader.readlines_no_new_line('words.italian.txt')

print(it_dict)

for word in split_file:
    if not word in it_dict:
        print(word)
