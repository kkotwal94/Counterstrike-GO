#include "stdafx.h"
////////////////////////
//       CT          //
///////////////////////

//GIGN
#define ct_gign_body ((Stride==32) && (NumVertices==4854) && (PrimitiveCount==7410))
#define ct_gign_head ((Stride==32) && (NumVertices==1645) && (PrimitiveCount==2568))
#define ct_gign_head2 ((Stride==32) && (NumVertices==1601) && (PrimitiveCount==2502))
#define ct_gign_head3 ((Stride==32) && (NumVertices==1611) && (PrimitiveCount==2522))
#define ct_gign_jambes ((Stride==32) && (NumVertices==1258) && (PrimitiveCount==1950))

#define ct_gign ct_gign_body || ct_gign_head || ct_gign_jambes || ct_gign_head2 || ct_gign_head3

//SEALs
#define ct_seal1_head ((Stride==32) && (NumVertices==4085) && (PrimitiveCount==4697))
#define ct_seal1_body ((Stride==32) && (NumVertices==5436) && (PrimitiveCount==8003))
#define ct_seal1_jambes ((Stride==32) && (NumVertices==2924) && (PrimitiveCount==3540))
#define ct_seal2_head ((Stride==32) && (NumVertices==3140) && (PrimitiveCount==3948))
#define ct_seal2_body ((Stride==32) && (NumVertices==5524) && (PrimitiveCount==8106))
#define ct_seal3_head ((Stride==32) && (NumVertices==2967) && (PrimitiveCount==3792))
#define ct_seal3_body ((Stride==32) && (NumVertices==5680) && (PrimitiveCount==8166))
#define ct_seal3_jambe ((Stride==32) && (NumVertices==2925) && (PrimitiveCount==3540))
#define ct_seal4_head ((Stride==32) && (NumVertices==3249) && (PrimitiveCount==4158))
#define ct_seal4_body ((Stride==32) && (NumVertices==5334) && (PrimitiveCount==7910))
#define ct_seal5_head ((Stride==32) && (NumVertices==4085) && (PrimitiveCount==4697))
#define ct_seal5_body ((Stride==32) && (NumVertices==5436) && (PrimitiveCount==8003))
#define ct_seal_body ((Stride==32) && (NumVertices==5547) && (PrimitiveCount==8003))
#define ct_seal_jambes ((Stride==32) && (NumVertices==2925) && (PrimitiveCount==3540))
#define ct_seal_head ((Stride==32) && (NumVertices==2539) && (PrimitiveCount==3527))


#define ct_seal ct_seal1_head || ct_seal1_body || ct_seal1_jambes || ct_seal2_head || ct_seal2_body || ct_seal3_head || ct_seal3_body \
        || ct_seal3_jambe|| ct_seal4_head || ct_seal4_body || ct_seal5_head || ct_seal5_body || ct_seal_body \
        || ct_seal_jambes || ct_seal_head

//FBI
#define ct_fbi_head ((Stride==32) && (NumVertices==2223) && (PrimitiveCount==3672))
#define ct_fbi_head2 ((Stride==32) && (NumVertices==2778) && (PrimitiveCount==4244))
#define ct_fbi_head3 ((Stride==32) && (NumVertices==2957) && (PrimitiveCount==4234))
#define ct_fbi_head4 ((Stride==32) && (NumVertices==4217) && (PrimitiveCount==2566))
#define ct_fbi_head5 ((Stride==32) && (NumVertices==993) && (PrimitiveCount==1722))
#define ct_fbi_body ((Stride==32) && (NumVertices==5395) && (PrimitiveCount==8657))
#define ct_fbi_jambes ((Stride==32) && (NumVertices==1646) && (PrimitiveCount==2714))

#define ct_fbi ct_fbi_jambes || ct_fbi_body || ct_fbi_head || ct_fbi_head2 || ct_fbi_head3 || ct_fbi_head4 || ct_fbi_head5

//IDF (ILE DE FRANCE)
#define ct_idf_head ((Stride==32) && (NumVertices==1677) && (PrimitiveCount==2713))
#define ct_idf_head2 ((Stride==32) && (NumVertices==1761) && (PrimitiveCount==2681))
#define ct_idf_jambes ((Stride==32) && (NumVertices==2118) && (PrimitiveCount==3354))
#define ct_idf_body ((Stride==32) && (NumVertices==4519) && (PrimitiveCount==6700))

#define ct_idf ct_idf_jambes || ct_idf_body || ct_idf_head || ct_idf_head2

//SAS
#define ct_sas_body ((Stride==32) && (NumVertices==5443) && (PrimitiveCount==8008))
#define ct_sas_body2 ((Stride==32) && (NumVertices==5050) && (PrimitiveCount==7423))
#define ct_sas_jambes ((Stride==32) && (NumVertices==4456) && (PrimitiveCount==5479))
#define ct_sas_head ((Stride==32) && (NumVertices==1219) && (PrimitiveCount==1749))

#define ct_sas ct_sas_jambes || ct_sas_body || ct_sas_head || ct_sas_body2

//SWAT
#define ct_swat1_head ((Stride==32) && (NumVertices==1835) && (PrimitiveCount==2898))
#define ct_swat1_jambes ((Stride==32) && (NumVertices==3654) && (PrimitiveCount==4030))
#define ct_swat1_body ((Stride==32) && (NumVertices==6112) && (PrimitiveCount==8261))
#define ct_swat2_head ((Stride==32) && (NumVertices==1883) && (PrimitiveCount==2986))
#define ct_swat2_jambes ((Stride==32) && (NumVertices==3654) && (PrimitiveCount==4030))
#define ct_swat2_body ((Stride==32) && (NumVertices==6018) && (PrimitiveCount==8022))
#define ct_swat3_head ((Stride==32) && (NumVertices==1834) && (PrimitiveCount==2898))
#define ct_swat3_body ((Stride==32) && (NumVertices==6090) && (PrimitiveCount==8226))
#define ct_swat4_head ((Stride==32) && (NumVertices==1980) && (PrimitiveCount==3074))
#define ct_swat4_body ((Stride==32) && (NumVertices==6777) && (PrimitiveCount==8930))
#define ct_swat5_body ((Stride==32) && (NumVertices==5679) && (PrimitiveCount==7713))
#define ct_swat5_head ((Stride==32) && (NumVertices==1917) && (PrimitiveCount==3004))

#define ct_swat ct_swat1_jambes || ct_swat1_body || ct_swat1_head || ct_swat2_jambes || ct_swat2_body || ct_swat2_head || ct_swat3_body || ct_swat3_head \
        || ct_swat4_body || ct_swat4_head || ct_swat5_body || ct_swat5_head

//GSG9
#define ct_gsg9_head ((Stride==32) && (NumVertices==2157) && (PrimitiveCount==3461))
#define ct_gsg9_head2 ((Stride==32) && (NumVertices==2113) && (PrimitiveCount==3391))
#define ct_gsg9_head3 ((Stride==32) && (NumVertices==2151) && (PrimitiveCount==3459))
#define ct_gsg9_body ((Stride==32) && (NumVertices==3301) && (PrimitiveCount==5424))
#define ct_gsg9_jambes ((Stride==32) && (NumVertices==1410) && (PrimitiveCount==2352))

#define ct_gsg9 ct_gsg9_jambes || ct_gsg9_body || ct_gsg9_head || ct_gsg9_head2 || ct_gsg9_head3


////////////////////////
//     TERRORIST      //
///////////////////////

//PIRATE
#define t_pirate_body ((Stride==32) && (NumVertices==7900) && (PrimitiveCount==9248))
#define t_pirate_jambes ((Stride==32) && (NumVertices==991) && (PrimitiveCount==1525))
#define t_pirate_head ((Stride==32) && (NumVertices==1314) && (PrimitiveCount==2367))
#define t_pirate_head2 ((Stride==32) && (NumVertices==1183) && (PrimitiveCount==2045))
#define t_pirate_head3 ((Stride==32) && (NumVertices==1380) && (PrimitiveCount==2493))
#define t_pirate_head4 ((Stride==32) && (NumVertices==1996) && (PrimitiveCount==2906))

#define t_pirate t_pirate_body || t_pirate_jambes || t_pirate_head || t_pirate_head2 || t_pirate_head3 || t_pirate_head4

//PHOENIX
#define t_phoenix_head ((Stride==32) && (NumVertices==876) && (PrimitiveCount==1630))
#define t_phoenix_jambes ((Stride==32) && (NumVertices==2593) && (PrimitiveCount==4097))
#define t_phoenix_body ((Stride==32) && (NumVertices==2944) && (PrimitiveCount==4916))

#define t_phoenix t_phoenix_head || t_phoenix_body || t_phoenix_jambes

//ANARCHISTE
#define t_anarchiste_jambes ((Stride==32) && (NumVertices==1671) && (PrimitiveCount==2876))
#define t_anarchiste_body ((Stride==32) && (NumVertices==3881) && (PrimitiveCount==6774))
#define t_anarchiste_head ((Stride==32) && (NumVertices==1925) && (PrimitiveCount==3314))

#define t_anarchiste t_anarchiste_jambes || t_anarchiste_body || t_anarchiste_head

//ELITE CREW
#define t_elitecrew1_head ((Stride==32) && (NumVertices==1310) && (PrimitiveCount==2302))
#define t_elitecrew1_jambes ((Stride==32) && (NumVertices==1887) && (PrimitiveCount==3088))
#define t_elitecrew1_body ((Stride==32) && (NumVertices==3816) && (PrimitiveCount==5930))
#define t_elitecrew2_head ((Stride==32) && (NumVertices==1372) && (PrimitiveCount==2286))
#define t_elitecrew2_cou ((Stride==32) && (NumVertices==128) && (PrimitiveCount==190))
#define t_elitecrew2_body ((Stride==32) && (NumVertices==3162) && (PrimitiveCount==5182))
#define t_elitecrew2_jambes ((Stride==32) && (NumVertices==1986) && (PrimitiveCount==3044))
#define t_elitecrew3_body ((Stride==32) && (NumVertices==2587) && (PrimitiveCount==4334))
#define t_elitecrew3_jambes ((Stride==32) && (NumVertices==2414) && (PrimitiveCount==3778))
#define t_elitecrew3_head ((Stride==32) && (NumVertices==1430) && (PrimitiveCount==2422))
#define t_elitecrew4_jambes ((Stride==32) && (NumVertices==2529) && (PrimitiveCount==3888))
#define t_elitecrew4_body ((Stride==32) && (NumVertices==3606) && (PrimitiveCount==5856))
#define t_elitecrew4_head ((Stride==32) && (NumVertices==1134) && (PrimitiveCount==2024))
#define t_elitecrew5_jambes ((Stride==32) && (NumVertices==2136) && (PrimitiveCount==3424))
#define t_elitecrew5_body ((Stride==32) && (NumVertices==2587) && (PrimitiveCount==4334))
#define t_elitecrew5_head ((Stride==32) && (NumVertices==1352) && (PrimitiveCount==2268))

#define t_elitecrew t_elitecrew1_jambes || t_elitecrew1_body || t_elitecrew1_head || t_elitecrew2_head || t_elitecrew2_cou || t_elitecrew2_body \
        || t_elitecrew2_jambes || t_elitecrew3_body || t_elitecrew3_jambes || t_elitecrew3_head || t_elitecrew4_jambes || t_elitecrew4_body \
        || t_elitecrew4_head || t_elitecrew5_jambes || t_elitecrew5_body || t_elitecrew5_head

//SEPARATISTE
#define t_separatiste_jambes ((Stride==32) && (NumVertices==2536) && (PrimitiveCount==4196))
#define t_separatiste_body ((Stride==32) && (NumVertices==3210) && (PrimitiveCount==5382))
#define t_separatiste_head ((Stride==32) && (NumVertices==1106) && (PrimitiveCount==2018))

#define t_separatiste t_separatiste_jambes || t_separatiste_body || t_separatiste_head

//PROFESSIONNEL
#define t_professionnel_head ((Stride==32) && (NumVertices==924) && (PrimitiveCount==1632))
#define t_professionnel_head2 ((Stride==32) && (NumVertices==1053) && (PrimitiveCount==1968))
#define t_professionnel_head3 ((Stride==32) && (NumVertices==646) && (PrimitiveCount==1248))
#define t_professionnel_head4 ((Stride==32) && (NumVertices==1197) && (PrimitiveCount==2256))
#define t_professionnel_head5 ((Stride==32) && (NumVertices==927) && (PrimitiveCount==1626))
#define t_professionnel_body ((Stride==32) && (NumVertices==5308) && (PrimitiveCount==8567))
#define t_professionnel_jambes ((Stride==32) && (NumVertices==2056) && (PrimitiveCount==3436))

#define t_professionnel t_professionnel_jambes || t_professionnel_body || t_professionnel_head || t_professionnel_head2 || t_professionnel_head3 \
        || t_professionnel_head4 || t_professionnel_head5

//BALKAN
#define t_balkan_head ((Stride==32) && (NumVertices==1624) && (PrimitiveCount==2936))
#define t_balkan_head2 ((Stride==32) && (NumVertices==1345) && (PrimitiveCount==2488))
#define t_balkan_head3 ((Stride==32) && (NumVertices==1214) && (PrimitiveCount==2292))
#define t_balkan_head4 ((Stride==32) && (NumVertices==1291) && (PrimitiveCount==2437))
#define t_balkan_head5 ((Stride==32) && (NumVertices==1215) && (PrimitiveCount==2286))
#define t_balkan_body ((Stride==32) && (NumVertices==5468) && (PrimitiveCount==8542))
#define t_balkan_jambes ((Stride==32) && (NumVertices==1273) && (PrimitiveCount==2113))

#define t_balkan t_balkan_jambes || t_balkan_body || t_balkan_head || t_balkan_head2 || t_balkan_head3 || t_balkan_head4 || t_balkan_head5


/////////////////
//   WEAPONS   //
/////////////////

//PISTOLET (Pistols)
//chargeur = magazine
#define usp ((Stride==32) && (NumVertices==1353) && (PrimitiveCount==1010))
#define uspchargeur ((Stride==32) && (NumVertices==140) && (PrimitiveCount==94))
#define glock ((Stride==32) && (NumVertices==2778) && (PrimitiveCount==2870))
#define glockchargeur ((Stride==32) && (NumVertices==290) && (PrimitiveCount==320))
#define dualberetta ((Stride==32) && (NumVertices==4894) && (PrimitiveCount==4222))
#define p228 ((Stride==32) && (NumVertices==1699) && (PrimitiveCount==1389))
#define p228chargeur ((Stride==32) && (NumVertices==143) && (PrimitiveCount==125))
#define fiveseven ((Stride==32) && (NumVertices==1426) && (PrimitiveCount==1175))
#define fivensevenchargeur ((Stride==32) && (NumVertices==94) && (PrimitiveCount==88))
#define tec ((Stride==32) && (NumVertices==2847) && (PrimitiveCount==2871))
#define tecchargeur ((Stride==32) && (NumVertices==170) && (PrimitiveCount==122))
#define deagle ((Stride==32) && (NumVertices==2252) && (PrimitiveCount==1587))
#define deaglechargeur ((Stride==32) && (NumVertices==112) && (PrimitiveCount==68))

#define  usp || uspchargeur || glock || glockchargeur || dualberetta || p228 || p228chargeur || fiveseven || tec || tecchargeur || deagle \
        || deaglechargeur

//LOURDE (Heavy)
#define nova ((Stride==32) && (NumVertices==2258) && (PrimitiveCount==2033))
#define xm1014 ((Stride==32) && (NumVertices==3811) && (PrimitiveCount==3149))
#define sawed ((Stride==32) && (NumVertices==2217) && (PrimitiveCount==2520))
#define mag7 ((Stride==32) && (NumVertices==2138) && (PrimitiveCount==1769))
#define mag7chargeur ((Stride==32) && (NumVertices==130) && (PrimitiveCount==70))
#define m249 ((Stride==32) && (NumVertices==4664) && (PrimitiveCount==3412))
#define negev ((Stride==32) && (NumVertices==4550) && (PrimitiveCount==3324))

#define lourde nova || xm1014 || sawed || mag7 || m249 || negev

//PMs (SMGs)
#define mp9 ((Stride==32) && (NumVertices==3851) && (PrimitiveCount==3143))
#define mp9chargeur ((Stride==32) && (NumVertices==216) && (PrimitiveCount==164))
#define uzi ((Stride==32) && (NumVertices==2729) && (PrimitiveCount==2870))
#define uzichargeur ((Stride==32) && (NumVertices==244) && (PrimitiveCount==186))
#define mp7 ((Stride==32) && (NumVertices==4536) && (PrimitiveCount==3155))
#define mp7chargeur ((Stride==32) && (NumVertices==151) && (PrimitiveCount==147))
#define ump45 ((Stride==32) && (NumVertices==3152) && (PrimitiveCount==2306))
#define ump45chargeur ((Stride==32) && (NumVertices==128) && (PrimitiveCount==66))
#define p90 ((Stride==32) && (NumVertices==4480) && (PrimitiveCount==3888))
#define p90chargeur ((Stride==32) && (NumVertices==225) && (PrimitiveCount==179))
#define ppbizon ((Stride==32) && (NumVertices==3320) && (PrimitiveCount==2871))
#define ppbizonchargeur ((Stride==32) && (NumVertices==680) && (PrimitiveCount==510))

#define pm mp9 || mp9chargeur || uzi || uzichargeur || mp7 || mp7chargeur || ump45 || ump45chargeur || p90 || p90chargeur || ppbizon || ppbizonchargeur

//FUSIL (Rifles)
#define famas ((Stride==32) && (NumVertices==3710) && (PrimitiveCount==3105))
#define famaschargeur ((Stride==32) && (NumVertices==161) && (PrimitiveCount==114))
#define galil ((Stride==32) && (NumVertices==4131) && (PrimitiveCount==2929))
#define galilchargeur ((Stride==32) && (NumVertices==166) && (PrimitiveCount==90))
#define m4 ((Stride==32) && (NumVertices==2615) && (PrimitiveCount==1924))
#define m4chargeur ((Stride==32) && (NumVertices==100) && (PrimitiveCount==68))
#define ak47 ((Stride==32) && (NumVertices==3637) && (PrimitiveCount==3123))
#define ak47chargeur ((Stride==32) && (NumVertices==125) && (PrimitiveCount==113))
#define ssg08 ((Stride==32) && (NumVertices==3045) && (PrimitiveCount==2370))
#define ssg08scope ((Stride==32) && (NumVertices==1690) && (PrimitiveCount==1732))
#define aug ((Stride==32) && (NumVertices==2171) && (PrimitiveCount==1874))
#define augchargeur ((Stride==32) && (NumVertices==92) && (PrimitiveCount==88))
#define augscope ((Stride==32) && (NumVertices==2893) && (PrimitiveCount==2989))
#define sig ((Stride==32) && (NumVertices==4375) && (PrimitiveCount==3398))
#define sigchargeur ((Stride==32) && (NumVertices==104) && (PrimitiveCount==68))
#define awp ((Stride==32) && (NumVertices==3687) && (PrimitiveCount==3382))
#define scar20 ((Stride==32) && (NumVertices==4557) && (PrimitiveCount==3049))
#define scar20chargeur ((Stride==32) && (NumVertices==48) && (PrimitiveCount==28))
#define g3sg1 ((Stride==32) && (NumVertices==3411) && (PrimitiveCount==2782))
#define g3sg1chargeur ((Stride==32) && (NumVertices==83) && (PrimitiveCount==46))

#define fusil famas || famaschargeur || galil || galilchargeur || m4 || m4chargeur || ak47 || ak47chargeur || ssg08 || ssg08scope || aug \
        || augscope || augchargeur || sig || sigchargeur || awp || scar20 || scar20chargeur || g3sg1 || g3sg1chargeur

#define smoke ((Stride==144) && (NumVertices==320) && (PrimitiveCount==160))
#define smoke2 ((Stride==144) && (NumVertices==60) && (PrimitiveCount==30))
#define smokegrenade ((Stride==32) && (NumVertices==789) && (PrimitiveCount==646))
#define hegrenade ((Stride==32) && (NumVertices==952) && (PrimitiveCount==1229))

#define ct_hand ((Stride==32) && (NumVertices==8772) && (PrimitiveCount==16398))
#define t_hand ((Stride==32) && (NumVertices==6954) && (PrimitiveCount==12834))