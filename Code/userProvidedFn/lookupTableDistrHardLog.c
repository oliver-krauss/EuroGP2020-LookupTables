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
8.414435718077062364983e-01, 8.426862214074268830899e-01, 8.440260682693109250962e-01, 8.452295371648335109427e-01, 8.463152758781664619647e-01, 8.476562962036318094050e-01, 8.488581943294304377190e-01, 8.499159408543143223724e-01, 8.511115733395769877845e-01, 8.522888261598794423790e-01, 
8.534731425469901378023e-01, 8.547810882964742562606e-01, 8.559598062178980226733e-01, 8.569848600162449647755e-01, 8.581506199421758962487e-01, 8.590402678431334759779e-01, 8.605567525782741311602e-01, 8.617371130128487211053e-01, 8.627577086244851978236e-01, 8.640226933726903313371e-01, 
8.650227988705426751537e-01, 8.662679463588510708760e-01, 8.674099424200927277440e-01, 8.685186478803637033508e-01, 8.696260064949213886010e-01, 8.706190271375607858673e-01, 8.717212145269308543050e-01, 8.729497461848809702900e-01, 8.739227365236563738193e-01, 8.750185928605257457136e-01, 
8.761170018876104359506e-01, 8.769202759252640033694e-01, 8.782841629171661557152e-01, 8.793596345398987379482e-01, 8.807997242853597974488e-01, 8.812343841451623083216e-01, 8.825817819093783045403e-01, 8.837658669009740286526e-01, 8.848398449928257525343e-01, 8.857637497469142973117e-01, 
8.868024071789741835659e-01, 8.878566109983848653187e-01, 8.890197794093910310664e-01, 8.900811700535777859500e-01, 8.911052103640320076750e-01, 8.920104477166339584926e-01, 8.931590447675556987406e-01, 8.941961514546507006074e-01, 8.950823472263857993880e-01, 8.962378625630660344825e-01, 
8.971184568813407311794e-01, 8.981302674879320102619e-01, 8.989335415255854666583e-01, 9.002822870672886335086e-01, 9.015069518685818739101e-01, 9.021579028064032890200e-01, 9.032811740858155413747e-01, 9.041366974128199895944e-01, 9.052529557862165621174e-01, 9.064549699993874609660e-01, 
9.071141531023159121361e-01, 9.080853588290583866538e-01, 9.090664434120913073301e-01, 9.101533050948861225393e-01, 9.107884308135387740890e-01, 9.119571750985930869149e-01, 9.130656027511595551616e-01, 9.138846326415565046730e-01, 9.149721617904519321840e-01, 9.158072289396105292170e-01, 
9.167558182965098723116e-01, 9.178285019039271741548e-01, 9.186471000008022969041e-01, 9.197294913368930791009e-01, 9.203102898554432753642e-01, 9.218012598178251248981e-01, 9.225398888781158879269e-01, 9.234664703139325858672e-01, 9.240930381638192692151e-01, 9.253310099635555507902e-01, 
9.261040288006258114351e-01, 9.273381023769126096923e-01, 9.280948360939804686609e-01, 9.287010999660630927721e-01, 9.299162967388838740845e-01, 9.306946804164919484492e-01, 9.317314049865111913462e-01, 9.324972224426114619789e-01, 9.334031726848758259152e-01, 9.343000235244849349669e-01, 
9.350377232614458522519e-01, 9.362207324291766941116e-01, 9.372789455613180775728e-01, 9.380150182237133593688e-01, 9.387503887751518227844e-01, 9.397832223878200830214e-01, 9.406634980929924338966e-01, 9.415373434734314317396e-01, 9.422934869999892715242e-01, 9.431519713267254578781e-01, 
9.440227997099432943884e-01, 9.449004860037061304112e-01, 9.456080149650785138249e-01, 9.466253009711731447595e-01, 9.476290247540699596129e-01, 9.484784298979445082978e-01, 9.495080127901061040063e-01, 9.503853532883695942601e-01, 9.509061757318681973317e-01, 9.519056437929536151898e-01, 
9.524617183241166351593e-01, 9.534620654651217996900e-01, 9.543186427442781338826e-01, 9.552834698356940101860e-01, 9.559833886794197876924e-01, 9.566674345822531178030e-01, 9.577917830299800261429e-01, 9.584894405017130303293e-01, 9.593166658837762872380e-01, 9.599517916024283836762e-01, 
9.609655193955720653420e-01, 9.618039152813548930965e-01, 9.624390410000075446462e-01, 9.632622649878859188988e-01, 9.643974881239030239044e-01, 9.652157166537153054620e-01, 9.658806394524690475123e-01, 9.670062954872166161024e-01, 9.677697730656218411127e-01, 9.683090037120528625891e-01, 
9.691093002283862611890e-01, 9.700498958116742231894e-01, 9.707243784545568354716e-01, 9.713595041732091539544e-01, 9.724480218565834110933e-01, 9.731185757609009945313e-01, 9.741883122786211268718e-01, 9.749965537332236920065e-01, 9.757539333820388627316e-01, 9.762730746464489683945e-01, 
9.770625319036455591615e-01, 9.778454231921029915497e-01, 9.786302554181371959885e-01, 9.797200639034755464962e-01, 9.799513801361839915316e-01, 9.812458279594566956661e-01, 9.818721794209706033030e-01, 9.825153670084205703716e-01, 9.834274924313077814730e-01, 9.842032751324324424402e-01, 
9.848208230684849517900e-01, 9.858450624769595771468e-01, 9.866047872845090660476e-01, 9.871105072404453562029e-01, 9.877456329590980077526e-01, 9.887744654022354584555e-01, 9.895327341912580898509e-01, 9.902864784868026237774e-01, 9.910172928764503508248e-01, 9.918967934892640725408e-01, 
9.923966466013707243832e-01, 9.931391076256629313335e-01, 9.938888347665500999639e-01, 9.945111215125908010748e-01, 9.956277280015574104866e-01, 9.963747439452497189905e-01, 9.967547413540646106256e-01, 9.977366640592845170588e-01, 9.984778041412922799935e-01, 9.992097076699975044534e-01, 
9.997027136312802708673e-01, 1.000548842497246182504e+00, 1.001431836657402207891e+00, 1.002163906725423769828e+00, 1.002636071677992513074e+00, 1.003363931772072614734e+00, 1.004184070380801596656e+00, 1.005056814125470543431e+00, 1.005602166252486329157e+00, 1.006315083420903810918e+00, 
1.006972565237040040387e+00, 1.008001700415127599442e+00, 1.008401300750115803240e+00, 1.009190414837704219408e+00, 1.010136007859321560787e+00, 1.010540154224649045389e+00, 1.011306339351866423470e+00, 1.012180673313536782842e+00, 1.012872136430158054310e+00, 1.013602394735929834724e+00, 
1.014129164354099499334e+00, 1.014985065641188288765e+00, 1.015712770702422718117e+00, 1.016471688498097103448e+00, 1.017097163997394915214e+00, 1.017636246928679488732e+00, 1.018504525675106409111e+00, 1.019245094437447374247e+00, 1.019634701682927468980e+00, 1.020404671205457969307e+00, 
1.021076198632516751630e+00, 1.021776986950366117313e+00, 1.022464201076663581347e+00, 1.023147222525233157597e+00, 1.023825958119719325978e+00, 1.024452079642037105600e+00, 1.025410494390607496484e+00, 1.025862653979485727973e+00, 1.026557069111601050437e+00, 1.027435565687047525074e+00, 
1.027894217942182830683e+00, 1.028789633776743039917e+00, 1.029389292365723962419e+00, 1.029860842837857726195e+00, 1.030570818563159241066e+00, 1.031255736424327995593e+00, 1.032075930726897627920e+00, 1.032743472631984626986e+00, 1.033241338182399049472e+00, 1.033852258519036393380e+00, 
1.034792557636837528889e+00, 1.035414115507722776499e+00, 1.035894609165685542607e+00, 1.036720205714764864169e+00, 1.037109812960245180946e+00, 1.037869721939914002817e+00, 1.038689459490643951511e+00, 1.039163086512930433969e+00, 1.039985094642185581293e+00, 1.040467911344449492006e+00, 
1.041074347186095927498e+00, 1.041942753471597482573e+00, 1.042564377012567877756e+00, 1.042953984258047528400e+00, 1.043862055803602251203e+00, 1.044496321573328723176e+00, 1.045174914104027186212e+00, 1.045785151641011934132e+00, 1.046487264788444893071e+00, 1.047065120274343286155e+00, 
1.047716178833398625869e+00, 1.048195667210169546024e+00, 1.048995129278604387935e+00, 1.049664743009783629546e+00, 1.050303982314357842398e+00, 1.050726912854057060187e+00, 1.051517023581661547382e+00, 1.052143103182823002939e+00, 1.052787140602539084355e+00, 1.053414570834211749784e+00, 
1.054016292298252333026e+00, 1.054649859960859581420e+00, 1.055080942847803848750e+00, 1.055702651521357005038e+00, 1.056510221031660368141e+00, 1.057182923017786269071e+00, 1.057414239250494825129e+00, 1.058219346615183464877e+00, 1.058837222569747771317e+00, 1.059446184549823533061e+00, 
1.060239202298753902198e+00, 1.060838739992424395453e+00, 1.061455842755133716082e+00, 1.062055348517171537992e+00, 1.062671214664825170004e+00, 1.063091575594882209899e+00, 1.063707532500483443627e+00, 1.064545798438228940697e+00, 1.064777114670937718799e+00, 1.065560829409310850124e+00, 
1.066162407053242944244e+00, 1.066920924957788896492e+00, 1.067561446654241796850e+00, 1.067951053899722557716e+00, 1.068729143846661511219e+00, 1.069169195798807425746e+00, 1.069750982212682943739e+00, 1.070512059626896439468e+00, 1.070938089170588414234e+00, 1.071749073261809792612e+00, 
1.072303074035122483210e+00, 1.072912817069233470946e+00, 1.073532835540202068358e+00, 1.074079860373237771398e+00, 1.074689776888386738563e+00, 1.075304982386413810147e+00, 1.075890334619994170851e+00, 1.076441691934504563122e+00, 1.076874167570458062926e+00, 1.077461601848627603673e+00, 
1.078060697402004164402e+00, 1.078603102898189947112e+00, 1.079218715242966419865e+00, 1.079764048697128941967e+00, 1.080521531323972217464e+00, 1.080954006959926605447e+00, 1.081554389397533233463e+00, 1.082121895752118589940e+00, 1.082834696055967160788e+00, 1.083260741656070447192e+00, 
1.083862210911951784453e+00, 1.084390531544528579744e+00, 1.085150717745881454590e+00, 1.085716874349734073490e+00, 1.086113655800232224991e+00, 1.086891670156136635583e+00, 1.087433033288130790339e+00, 1.088022728742872535790e+00, 1.088409874115254805105e+00, 1.089170700213283549118e+00, 
1.089718360876565927953e+00, 1.090285425256324769450e+00, 1.090668126983242114392e+00, 1.091234701712150201303e+00, 1.091984565930587347538e+00, 1.092355072803271154314e+00, 1.093110690241250848587e+00, 1.093674615854584475372e+00, 1.094042593652590156239e+00, 1.094796901637524522144e+00, 
1.095361230656316964271e+00, 1.095887696028321478536e+00, 1.096430135223380064602e+00, 1.096797803795854120423e+00, 1.097544397419756290191e+00, 1.098126000769535703938e+00, 1.098663939344910467355e+00, 1.099215356030193824211e+00, 1.099773337313272536520e+00, 1.100333760713882336191e+00, 
1.100876627453522882405e+00, 1.101268584185996379787e+00, 1.101967435058238908852e+00, 1.102356973621510416450e+00, 1.103062107510613065742e+00, 1.103588061754774196643e+00, 1.104135722418056797522e+00, 1.104530991839907105856e+00, 1.105217431133433958479e+00, 1.105597697560060987954e+00, 
1.106325580668448216315e+00, 1.106859181025919625085e+00, 1.107229687898603653906e+00, 1.107917269195398013437e+00, 1.108474362954966929706e+00, 1.108851117054874046985e+00, 1.109379408109799181048e+00, 1.110089721623834568831e+00, 1.110627941042616306788e+00, 1.110975896730409751001e+00, 
1.111678270400814794172e+00, 1.112205493760904051470e+00, 1.112740255800137134656e+00, 1.113284007113016338408e+00, 1.113795667329403826784e+00, 1.114166174202087189471e+00, 1.114858418234116799184e+00, 1.115228925106800383915e+00, 1.115910572478689299913e+00, 1.116456559968393325022e+00, 
1.116990225943414349885e+00, 1.117487797156647699737e+00, 1.118018062168286697045e+00, 1.118530664564961529805e+00, 1.119069158416182485638e+00, 1.119603994483337583432e+00, 1.120125292507624603644e+00, 1.120628502289772399081e+00, 1.120999009162455761768e+00, 1.121668758671680254935e+00, 
1.122032530953450457645e+00, 1.122723810144032219327e+00, 1.123227698510550043309e+00, 1.123569188978149613334e+00, 1.124097480033074525352e+00, 1.124785419062185543027e+00, 1.125269005775690223103e+00, 1.125800750253697080083e+00, 1.126328957730244439972e+00, 1.126831133679197183284e+00, 
1.127184732133880817884e+00, 1.127843937594848355843e+00, 1.128343440100670225235e+00, 1.128730607779508732236e+00, 1.129383899439295291245e+00, 1.129730702618336524168e+00, 1.130387544510489394867e+00, 1.130745558219457880256e+00, 1.131253197237336083347e+00, 1.131765027776926224590e+00, 
1.132409762097935868042e+00, 1.132931438049321171135e+00, 1.133417097363326631054e+00, 1.133785158776966506267e+00, 1.134437207024649341136e+00, 1.134920943820488581366e+00, 1.135436518528226246261e+00, 1.135932980948207271510e+00, 1.136436687626070085599e+00, 1.136928945879374985850e+00, 
1.137417910258762709930e+00, 1.137927282752665636423e+00, 1.138410523156786036125e+00, 1.138767707829807740438e+00, 1.139255106910147308241e+00, 1.139770485717271242265e+00, 1.140275234006418614285e+00, 1.140764624117998060626e+00, 1.141405334158952955548e+00, 1.141875671097233757578e+00, 
1.142380692886869608671e+00, 1.142718183968705725206e+00, 1.143215239871059107912e+00, 1.143843300253267081246e+00, 1.144340475871487017301e+00, 1.144825215959440978253e+00, 1.145159480827751652399e+00, 1.145664098992956958512e+00, 1.146278075746381519551e+00, 1.146757939691061434218e+00, 
1.147247065176522085039e+00, 1.147732246199885786098e+00, 1.148227146327895242806e+00, 1.148709390092603310762e+00, 1.149179238439330230648e+00, 1.149528712186551393515e+00, 1.150141606060141485912e+00, 1.150633865193385618753e+00, 1.151101305696923038369e+00, 1.151590605920678633822e+00, 
1.152057578419395600378e+00, 1.152550957350755078679e+00, 1.153026884557793341202e+00, 1.153505901691870061399e+00, 1.153849016854975539914e+00, 1.154464520049700793081e+00, 1.154764143850346869158e+00, 1.155258534946907778007e+00, 1.155755317672440662946e+00, 1.156225408785431563174e+00, 
1.156700166789115025168e+00, 1.157178469758024519365e+00, 1.157650989664688268022e+00, 1.158254502288925680276e+00, 1.158594654965187764617e+00, 1.159075223410184429795e+00, 1.159661511003708511680e+00, 1.160149478190417804413e+00, 1.160585562676188509101e+00, 1.161069304713512551075e+00, 
1.161536103604974279335e+00, 1.161864336068998637685e+00, 1.162349479327967172182e+00, 1.162936837946636048358e+00, 1.163393750741498200441e+00, 1.163875162098831905766e+00, 1.164325817007899610545e+00, 1.164777176204368602797e+00, 1.165252200833015283621e+00, 1.165723856099712296697e+00, 
1.166032300431835366794e+00, 1.166514285145929363807e+00, 1.166984517855668590514e+00, 1.167555557650809427983e+00, 1.168006971239904157045e+00, 1.168349670910528548262e+00, 1.168814949841922468110e+00, 1.169270805842983040890e+00, 1.169860715731572353704e+00, 1.170305335054426798536e+00, 
1.170637220494801011839e+00, 1.171106169340420555258e+00, 1.171678753981893805758e+00, 1.171997262729491895428e+00, 1.172472754395545546657e+00, 1.173065619158233596764e+00, 1.173378761896554323130e+00, 1.173836384537948918094e+00, 1.174278515099083541884e+00, 1.174854589544942484736e+00, 
1.175302982549896402276e+00, 1.175751802821523028797e+00, 1.176206502760926086992e+00, 1.176533606072290405464e+00, 1.176986387676528300616e+00, 1.177551766704465263658e+00, 1.177996004769830795667e+00, 1.178445063107685264470e+00, 1.178895779098009688468e+00, 1.179218556695127428924e+00, 
1.179683102270632888420e+00, 1.180131074756878284404e+00, 1.180563521484284006391e+00, 1.181129681624470961765e+00, 1.181574406539489086043e+00, 1.181898732298036547306e+00, 1.182455649060972557862e+00, 1.182779974819520019125e+00, 1.183339989218264998172e+00, 1.183776905148201441520e+00, 
1.184101230906748458693e+00, 1.184665494943065500166e+00, 1.185088060117454045184e+00, 1.185542159374732174015e+00, 1.185993458605519634830e+00, 1.186422302338042467085e+00, 1.186756657727880748254e+00, 1.187189688140909415992e+00, 1.187719636083155672068e+00, 1.188163056238512149676e+00, 
1.188605674016419921912e+00, 1.188935642172935569505e+00};