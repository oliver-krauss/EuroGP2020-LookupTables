/**
 * Archetype - cmaesRunner will create NEW files.
 * @author Oliver Krauss @date 21 Aug 2019
 */

/**
 * lower end of the range the lookup table was generated for
 */
const double lower_end = 0.5;

/**
 * higher end of the range the lookup table was used for
 */
const double higher_end = 2.0;

/**
 * Helper constant equals the size of the lookup table
 */
const int table_size = 512;

/**
 * Lookup table for the ranges between lower_end and higher_end.
 * DO NOT MODIFY > this is generated by CMA_ES. Use cmaesRunner.c to update values to fit userProvidedFunction.c
 */
double lookupTable[512] = {
8.431990128509303517035e-01, 8.471201999184664321874e-01, 8.437576159032142975036e-01, 8.476788029707502669652e-01, 8.515999900382862364268e-01, 8.482374060230343237876e-01, 8.521585930905701822269e-01, 8.560797801581061516885e-01, 8.527171961428542390493e-01, 8.566383832103904305555e-01, 
8.532757991951387399610e-01, 8.571969862626747094225e-01, 8.611181733302107899064e-01, 8.538985942258692229956e-01, 8.578197812934051924572e-01, 8.617409683609411619187e-01, 8.656621554284771313803e-01, 8.622995714132253297635e-01, 8.662207584807614102473e-01, 8.628581744655092755636e-01, 
8.667793615330452450252e-01, 8.707005486005813255090e-01, 8.673379645853296349145e-01, 8.712591516528656043761e-01, 8.751803387204015738376e-01, 8.718177547051499942654e-01, 8.757389417726859637270e-01, 8.723763577574341621101e-01, 8.762975448249701315717e-01, 8.802187318925062120556e-01, 
8.768561478772540773718e-01, 8.807773349447900468334e-01, 8.774147509295382452166e-01, 8.813359379970743257005e-01, 8.852571250646104061843e-01, 8.818945410493586045675e-01, 8.858157281168946850514e-01, 8.824531441016426613899e-01, 8.863743311691786308515e-01, 8.902955182367144892908e-01, 
8.869329342214627986962e-01, 8.908541212889988791801e-01, 8.947753083565348486417e-01, 8.914127243412830470248e-01, 8.953339114088191275087e-01, 8.919713273935674369142e-01, 8.958925144611034063757e-01, 8.998137015286394868596e-01, 8.964511175133874631982e-01, 9.003723045809234326597e-01, 
8.970097205656715200206e-01, 9.009309076332076005045e-01, 9.048520947007436809884e-01, 9.014895106854918793715e-01, 9.054106977530280708777e-01, 9.020481137377762692608e-01, 9.059693008053122387224e-01, 9.098904878728482081840e-01, 9.026709087685069743401e-01, 9.065920958360430548240e-01, 
9.105132829035791353078e-01, 9.144344699711151047694e-01, 9.117749001636697991913e-01, 9.156960872312059906974e-01, 9.130365174237605740970e-01, 9.169577044912964325363e-01, 9.135951204760447419417e-01, 9.175163075435808224256e-01, 9.141537235283290208088e-01, 9.180749105958649902703e-01, 
9.219960976634010707542e-01, 9.186335136481492691374e-01, 9.225547007156852385990e-01, 9.191921167004336590267e-01, 9.231133037679696284883e-01, 9.270344908355055979499e-01, 9.243749210280600703271e-01, 9.282961080955959287664e-01, 9.249335240803443491941e-01, 9.288547111478803186557e-01, 
9.254921271326281839720e-01, 9.294133142001642644559e-01, 9.333345012677002339174e-01, 9.306749314602547062947e-01, 9.345961185277905647339e-01, 9.312335345125385410725e-01, 9.351547215800745105341e-01, 9.317921375648228199395e-01, 9.357133246323589004234e-01, 9.396345116998946478404e-01, 
9.369749418924494532845e-01, 9.408961289599856447907e-01, 9.382365591525401171680e-01, 9.421577462200761976518e-01, 9.387951622048241739904e-01, 9.427163492723603654966e-01, 9.466375363398963349582e-01, 9.439779665324511404023e-01, 9.478991535999873319085e-01, 9.452395837925419153080e-01, 
9.491607708600781068142e-01, 9.465012010526325791915e-01, 9.504223881201684376308e-01, 9.477628183127232430749e-01, 9.516840053802594345811e-01, 9.483214213650078550089e-01, 9.522426084325438244704e-01, 9.561637955000797939320e-01, 9.535042256926342663093e-01, 9.574254127601701247485e-01, 
9.547658429527249301927e-01, 9.586870300202611216989e-01, 9.560274602128155940761e-01, 9.599486472803516745600e-01, 9.572890774729062579596e-01, 9.617074484466714423547e-01, 9.590478786392262477989e-01, 9.629690657067623282828e-01, 9.603094958993171337269e-01, 9.642306829668533252331e-01, 
9.615711131594077976104e-01, 9.654923002269438780942e-01, 9.621297162116918544328e-01, 9.660509032792280459390e-01, 9.699720903467640154005e-01, 9.673125205393184877778e-01, 9.712337076068545682617e-01, 9.685741377994093737058e-01, 9.724953248669453431674e-01, 9.653027231968559496167e-01, 
9.692239102643919190783e-01, 9.731450973319278885398e-01, 9.770662843994640800460e-01, 9.744067145920188854902e-01, 9.783279016595548549518e-01, 9.756683318521093273290e-01, 9.795895189196451857683e-01, 9.769299491121998801901e-01, 9.808511361797359606740e-01, 9.781915663722906550959e-01, 
9.821127534398267355797e-01, 9.794531836323815410239e-01, 9.833743706999175104855e-01, 9.807148008924719828627e-01, 9.846359879600078413020e-01, 9.819764181525625357239e-01, 9.858976052200988382523e-01, 9.832380354126533106296e-01, 9.871592224801893911135e-01, 9.844996526727441965576e-01, 
9.884208397402801660192e-01, 9.857612699328346383965e-01, 9.896824570003704968357e-01, 9.936036440679066883419e-01, 9.909440742604614937861e-01, 9.948652613279974632476e-01, 9.922056915205519356249e-01, 9.961268785880877940642e-01, 9.934673087806424884860e-01, 9.973884958481787910145e-01, 
9.947289260407334854364e-01, 9.986501131082697879648e-01, 9.959905433008245934090e-01, 9.999117303683605628706e-01, 9.972521605609150352478e-01, 1.001173347628450782665e+00, 9.985137778210055881090e-01, 1.002434964888542001660e+00, 9.997753950810969181262e-01, 1.003696582148632776565e+00, 
1.001037012341187804054e+00, 1.004958199408723773516e+00, 1.002298629601278134871e+00, 1.006219816668813882288e+00, 1.003560246861368687732e+00, 1.007978617835133983149e+00, 1.000786016165045255732e+00, 1.004707203232581669283e+00, 1.008628390300117638745e+00, 1.012549577367653830251e+00, 
1.009890007560208191606e+00, 1.013811194627743939023e+00, 1.011151624820299188556e+00, 1.015072811887835602107e+00, 1.012413242080390629596e+00, 1.016334429147927043147e+00, 1.017757153150197879654e+00, 1.015097583342752463054e+00, 1.012438013535306824409e+00, 1.016359200602842571826e+00, 
1.020280387670378985376e+00, 1.017620817862933568776e+00, 1.021542004930469760282e+00, 1.018882435123024787771e+00, 1.022803622190560757232e+00, 1.020144052383116006766e+00, 1.024065239450651754183e+00, 1.021405669643206559627e+00, 1.025326856710742973178e+00, 1.022667286903297556577e+00, 
1.026588473970833970128e+00, 1.023928904163388553528e+00, 1.027850091230924745034e+00, 1.025190521423479106389e+00, 1.029111708491014853806e+00, 1.026452138683569659250e+00, 1.030373325751106072801e+00, 1.027713755943660656200e+00, 1.031634943011197069751e+00, 1.028975373203751653151e+00, 
1.032896560271287844657e+00, 1.030236990463842206012e+00, 1.034158177531377953429e+00, 1.031498607723932758873e+00, 1.035916978697698054290e+00, 1.033257408890253081779e+00, 1.037178595957789051241e+00, 1.034519026150344078729e+00, 1.038440213217880048191e+00, 1.035780643410434409546e+00, 
1.039701830477970156963e+00, 1.037042260670524962407e+00, 1.040963447738061375958e+00, 1.041225013788051878549e+00, 1.038565443980606461949e+00, 1.042486631048142209366e+00, 1.035294029378053703994e+00, 1.039215216445589673455e+00, 1.043633587419354746828e+00, 1.040974017611909330228e+00, 
1.044895204679445521734e+00, 1.048816391746981269151e+00, 1.041623790076892319689e+00, 1.045544977144428289151e+00, 1.042885407336983538684e+00, 1.046806594404519952235e+00, 1.050727781472055921697e+00, 1.043535179801967194280e+00, 1.047456366869503607830e+00, 1.051377553937039577292e+00, 
1.048717984129594604781e+00, 1.052639171197130574242e+00, 1.053048855452068943706e+00, 1.056970042519605357256e+00, 1.054310472712159940656e+00, 1.058231659779696132162e+00, 1.055572089972251159651e+00, 1.052912520164805743050e+00, 1.056833707232341934557e+00, 1.060754894299877681973e+00, 
1.058095324492432487418e+00, 1.062016511559968900968e+00, 1.059356941752523484368e+00, 1.063278128820059897919e+00, 1.060618559012614481318e+00, 1.057958989205169508807e+00, 1.061880176272705700313e+00, 1.059220606465260283713e+00, 1.063141793532796475219e+00, 1.060482223725351724752e+00, 
1.064403410792887472169e+00, 1.057210809122798522708e+00, 1.061131996190334492169e+00, 1.057769412175082912597e+00, 1.061690599242618882059e+00, 1.065611786310155295610e+00, 1.069532973377691265071e+00, 1.066873403570246514604e+00, 1.068296127572517573157e+00, 1.072217314640053764663e+00, 
1.069557744832608792152e+00, 1.062365143162519842690e+00, 1.066286330230055812152e+00, 1.070207517297592225702e+00, 1.074128704365128195164e+00, 1.071469134557682556519e+00, 1.075390321625218303936e+00, 1.072730751817773109380e+00, 1.076651938885309522931e+00, 1.073992369077864328375e+00, 
1.077913556145400297837e+00, 1.075253986337955325325e+00, 1.079175173405491294787e+00, 1.080597897407762575384e+00, 1.077938327600317824917e+00, 1.081859514667854238468e+00, 1.079199944860408821867e+00, 1.076540375052963627311e+00, 1.080461562120500040862e+00, 1.077801992313054624262e+00, 
1.081723179380591037813e+00, 1.082112731055498322519e+00, 1.079453161248052905918e+00, 1.083374348315589097425e+00, 1.080714778508144124913e+00, 1.084635965575680094375e+00, 1.081976395768235121864e+00, 1.085897582835771091325e+00, 1.078704981165682585953e+00, 1.082626168233218555415e+00, 
1.086547355300754746921e+00, 1.090468542368291160471e+00, 1.087808972560845743871e+00, 1.091730159628382157422e+00, 1.084537557958292985916e+00, 1.088458745025829177422e+00, 1.092379932093365146883e+00, 1.093802656095636649525e+00, 1.091143086288191677014e+00, 1.095064273355728090564e+00, 
1.092404703548282673964e+00, 1.093827427550553510471e+00, 1.091167857743108537960e+00, 1.095089044810644507422e+00, 1.092429475003199534910e+00, 1.096350662070735726417e+00, 1.100271849138271695878e+00, 1.097612279330826945412e+00, 1.101533466398363136918e+00, 1.098873896590918386451e+00, 
1.096214326783473191895e+00, 1.100135513851009383401e+00, 1.092942912180920655985e+00, 1.096864099248457069535e+00, 1.094204529441011652935e+00, 1.098125716508547844441e+00, 1.102046903576084035947e+00, 1.099387333768638397302e+00, 1.103308520836174810853e+00, 1.100648951028729838342e+00, 
1.104570138096266251893e+00, 1.101910568288820835292e+00, 1.105831755356357248843e+00, 1.103172185548911832242e+00, 1.107093372616448245793e+00, 1.111014559683984215255e+00, 1.108354989876539464788e+00, 1.105695420069094714322e+00, 1.109616607136630905828e+00, 1.102424005466542400455e+00, 
1.106345192534078369917e+00, 1.110266379601614561423e+00, 1.114187566669150974974e+00, 1.111527996861705558374e+00, 1.108868427054260807907e+00, 1.112789614121796999413e+00, 1.116710801189333412964e+00, 1.114051231381888218408e+00, 1.115473955384159054915e+00, 1.112814385576714082404e+00, 
1.110154815769269331938e+00, 1.114076002836805523444e+00, 1.117997189904341936995e+00, 1.115337620096896520394e+00, 1.119258807164432933945e+00, 1.120681531166703770452e+00, 1.118021961359258575897e+00, 1.121943148426794767403e+00, 1.114750546756705595897e+00, 1.111387962741453794280e+00, 
1.115309149808989763741e+00, 1.119230336876525511158e+00, 1.123151523944061924709e+00, 1.120491954136616952198e+00, 1.124413141204153143704e+00, 1.121753571396708171193e+00, 1.125674758464244362699e+00, 1.123015188656798946099e+00, 1.126936375724335359649e+00, 1.124276805916890387138e+00, 
1.128306730205030472547e+00, 1.125647160397585055946e+00, 1.122987590590140305480e+00, 1.126908777657676496986e+00, 1.124249207850231746519e+00, 1.128279132138371609884e+00, 1.132200319205907801390e+00, 1.129540749398463050923e+00, 1.133461936465998798340e+00, 1.126269334795909848879e+00, 
1.127692058798180463342e+00, 1.131613245865716876892e+00, 1.135534432933252846354e+00, 1.132874863125807207709e+00, 1.136796050193343621260e+00, 1.134136480385898648748e+00, 1.138057667453435062299e+00, 1.135398097645989645699e+00, 1.132738527838544895232e+00, 1.136659714906081308783e+00, 
1.134000145098635892182e+00, 1.137921332166172305733e+00, 1.135261762358726889133e+00, 1.139182949426263302684e+00, 1.136523379618817886083e+00, 1.140444566686354299634e+00, 1.137784996878909327123e+00, 1.141706183946445740673e+00, 1.134513582276357013257e+00, 1.138434769343892982718e+00, 
1.142355956411429396269e+00, 1.143778680413700454821e+00, 1.136586078743611727404e+00, 1.140507265811148140955e+00, 1.144428452878684110416e+00, 1.137235851208595383000e+00, 1.141157038276131796550e+00, 1.145078225343667766012e+00, 1.148999412411203513429e+00, 1.141806810741115008057e+00, 
1.145727997808651199563e+00, 1.149649184876187169024e+00, 1.142456583206098663652e+00, 1.146377770273634855158e+00, 1.143718200466189438558e+00, 1.147639387533725630064e+00, 1.151560574601261821570e+00, 1.148901004793816849059e+00, 1.152822191861353040565e+00, 1.150162622053907623965e+00, 
1.142970020383819118592e+00, 1.146891207451355088054e+00, 1.150812394518891279560e+00, 1.154733581586427693111e+00, 1.152074011778982276510e+00, 1.155995198846518690061e+00, 1.153335629039073273461e+00, 1.150676059231628300950e+00, 1.154597246299164270411e+00, 1.158518433366700683962e+00, 
1.155858863559255711451e+00, 1.153199293751810960984e+00, 1.157120480819347152490e+00, 1.154460911011902402024e+00, 1.158382098079438593530e+00, 1.155722528271993398974e+00, 1.159643715339529812525e+00, 1.156984145532084395924e+00, 1.160905332599620809475e+00, 1.158245762792175392875e+00, 
1.162166949859711806425e+00, 1.159507380052266389825e+00, 1.163428567119802803376e+00, 1.160768997312357830864e+00, 1.164690184379894244415e+00, 1.166123794145264236377e+00, 1.158931192475175731005e+00, 1.162852379542711700466e+00, 1.166773566610248114017e+00, 1.164113996802803141506e+00, 
1.168035183870339555057e+00, 1.168424735545246617718e+00, 1.165765165737801867252e+00, 1.169686352805338058758e+00, 1.167026782997892864202e+00, 1.164367213190448113735e+00, 1.168288400257983861152e+00, 1.165628830450539110686e+00, 1.169550017518075302192e+00, 1.166890447710630551725e+00, 
1.170811634778166743232e+00, 1.163619033108078015815e+00, 1.168037404081843533277e+00, 1.171958591149379502738e+00, 1.169299021341934530227e+00, 1.166639451534489335671e+00, 1.170560638602025305133e+00, 1.174481825669561718684e+00, 1.171822255862116746172e+00, 1.175743442929653159723e+00, 
1.173083873122207743123e+00, 1.177005060189744156673e+00, 1.174345490382298740073e+00, 1.178266677449835153624e+00, 1.175607107642389737023e+00, 1.179528294709926150574e+00, 1.176868724902481178063e+00, 1.180789911970017591614e+00, 1.178130342162572619102e+00, 1.182051529230109032653e+00, 
1.179391959422664060142e+00, 1.176732389615219309675e+00, 1.169539787945130582258e+00, 1.171525321429997434919e+00, 1.175446508497533848470e+00, 1.179367695565070039976e+00, 1.183288882632606009437e+00, 1.180629312825161258971e+00, 1.184550499892697672522e+00, 1.181890930085252255921e+00, 
1.185812117152788669472e+00, 1.183152547345343696961e+00, 1.187073734412880110511e+00, 1.184414164605435138000e+00, 1.188335351672971551551e+00, 1.185675781865526579040e+00, 1.189596968933062770546e+00, 1.186937399125618020079e+00, 1.190858586193154211585e+00, 1.188199016385709461119e+00, 
1.185539446578264710652e+00, 1.189460633645801124203e+00, 1.186801063838355707603e+00, 1.190722250905892121153e+00, 1.188062681098446704553e+00, 1.191983868165983118104e+00, 1.189324298358538145592e+00, 1.193245485426074559143e+00, 1.190585915618629586632e+00, 1.194507102686166000183e+00, 
1.187314501016077272766e+00, 1.191235688083613464272e+00};