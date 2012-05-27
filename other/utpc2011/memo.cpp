
//copy map

map<LL, int> aaa;
map<LL, int> bbb;

for(map<LL, int>::iterator it = aaa.begin(); it != aaa.end(); it++) {
	pair<map<LL, int>::iterator, bool> pr = bbb.insert(*it);
	if(!pr.second)
		pr.first->second = it->second;
}
