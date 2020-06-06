#include<vector>
#include<string>
#include<iostream>
#include "automat.hpp"
#include "rab_kra_kmp.hpp"
#include "b_m.hpp"
int main(){
	bm kek;
	std::string kuk = "ipsum";//"ipsumssgsgseipsumsumsms";
	std::string kuk1 ="ipsumLoremipsumdolorsitametconsecteturadipiscingelitCrasatenimlectusNunatviverraaugueQuisquenoncondimentummaurisSedpretiumornaIPsUMrescelipsumerisqueMaecenaseununcipsumaculisluctusrisusvitaetempusleoMorbiquisbibendumliberoeumaximusligulaNunchendreritaccumsanmalesuadaipsum";
	std::cout<<kuk1.size()<<std::endl;
	automat kkk;
//	kkk.make_graph(kuk);
	std::vector<int> pos(0);
//	rabin_kramp(kuk1,kuk,pos);
	kkk.search(kuk1, kuk,pos);
//	KMP(kuk1,kuk,pos);
	for(auto i:pos)
		std::cout<<i<<" - "<<kuk1.substr(i,kuk.size())<<std::endl;
//	kek.make_suf_stop(kuk);
//	kek.pri();
	return 0;
}
