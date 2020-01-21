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
8.414435718077062364983e-01, 8.426862214074268830899e-01, 8.440260682693109250962e-01, 8.452295371648335109427e-01, 8.463152758781664619647e-01, 8.476701854458080775956e-01, 8.487238338558205086315e-01, 8.499145995656056662426e-01, 8.510973613426939810012e-01, 8.524342414268051282278e-01, 
8.536228163539592017628e-01, 8.546387272980211502471e-01, 8.559594083342173531648e-01, 8.569846313092126521838e-01, 8.581359194574703641578e-01, 8.594268068382171499309e-01, 8.606034174241382617154e-01, 8.617490984391952268950e-01, 8.627559878307677898590e-01, 8.639933111556179490265e-01, 
8.650081797336576228119e-01, 8.661563826679479216608e-01, 8.674104847322363642803e-01, 8.685222270879151551526e-01, 8.695294445674082162157e-01, 8.707682944951770087627e-01, 8.717219451976326860532e-01, 8.728443317567761150499e-01, 8.739259994950956400572e-01, 8.750169674073637882117e-01, 
8.762584824974517516694e-01, 8.773382570849820316639e-01, 8.784203178547598245274e-01, 8.793611622989102594161e-01, 8.805613441679048802868e-01, 8.816489591923012403285e-01, 8.825831427909279769395e-01, 8.836301449483381365013e-01, 8.846944262480376242053e-01, 8.858807034977144168053e-01, 
8.869444589749504448406e-01, 8.880020694918538959328e-01, 8.889126978987350602424e-01, 8.900807246856722310113e-01, 8.909829583066471991870e-01, 8.919953760315585400420e-01, 8.931592713781643100290e-01, 8.940683440155526851001e-01, 8.952299524682905129680e-01, 8.962547237550148038210e-01, 
8.971188815792080495370e-01, 8.981302517981348820797e-01, 8.992811127027011686152e-01, 9.002993776114801560695e-01, 9.012825519042122479618e-01, 9.021591497987665464464e-01, 9.032961058582708036013e-01, 9.041360917680619779802e-01, 9.052488586529293668193e-01, 9.062559750296526051017e-01, 
9.072215732109571995068e-01, 9.080850120092559540907e-01, 9.091812683304318909450e-01, 9.101501962636827647302e-01, 9.109949881165086971180e-01, 9.121078323320246372674e-01, 9.129261472679446320910e-01, 9.140311171201813689180e-01, 9.149725322572075381089e-01, 9.157901524903429013591e-01, 
9.167396388265590667643e-01, 9.176936239188150379320e-01, 9.186492019274150599983e-01, 9.197282264531428941368e-01, 9.205360016264390043972e-01, 9.215950037479737622093e-01, 9.223889367143760509293e-01, 9.234637597048154233903e-01, 9.244073513945879616571e-01, 9.251836753473932084546e-01, 
9.262568141632031570865e-01, 9.270444791395500150344e-01, 9.280941308190588934224e-01, 9.288775870605157081172e-01, 9.297646555313403560206e-01, 9.308160924811788028421e-01, 9.315822912448620263248e-01, 9.326396859022225704905e-01, 9.335371711203448441552e-01, 9.343023310353631982750e-01, 
9.353377175714775448867e-01, 9.360793397675865046281e-01, 9.369956902342618798585e-01, 9.380147328354730973388e-01, 9.389018946618110650348e-01, 9.397839937125324061284e-01, 9.405194797311011711827e-01, 9.413877971583003434475e-01, 9.424060521816908231330e-01, 9.431528442652672428181e-01, 
9.440216989169639694168e-01, 9.450433855695113960493e-01, 9.459057174482304874985e-01, 9.467757504614282559885e-01, 9.476300371806454236889e-01, 9.483474390945845211576e-01, 9.492163086462873655691e-01, 9.500569441285451333101e-01, 9.509041340058227431697e-01, 9.517580397176602646780e-01, 
9.526121146463008004801e-01, 9.534590244527647584505e-01, 9.544237163963722458959e-01, 9.551242700631278337298e-01, 9.559673274430023903747e-01, 9.568139425020087962537e-01, 9.577961895060438379801e-01, 9.586189063584509284510e-01, 9.594523409281940917737e-01, 9.601488748421446173253e-01, 
9.609674085064660031819e-01, 9.617848552976910880830e-01, 9.626259130334612335034e-01, 9.635803452414272163296e-01, 9.642459118468467149654e-01, 9.650623593558319557317e-01, 9.658801737082707283832e-01, 9.666905915437241647581e-01, 9.675048063514422036491e-01, 9.682952020770164702768e-01, 
9.691077881694124540601e-01, 9.700539376311919648188e-01, 9.708738897474519236042e-01, 9.715208257467503605298e-01, 9.723250598591414162186e-01, 9.732660037679724540638e-01, 9.739087976094905618751e-01, 9.746951801934264913996e-01, 9.754855480587071303589e-01, 9.762708437471363520643e-01, 
9.770650652976157202190e-01, 9.778445085896350086330e-01, 9.787816867767725748095e-01, 9.794218628685091854180e-01, 9.801961064768693887572e-01, 9.809596711031796090197e-01, 9.818732218343846351871e-01, 9.825002778252015511740e-01, 9.832805247134768222850e-01, 9.840442872095305215652e-01, 
9.849772424331769693495e-01, 9.857297776810406420012e-01, 9.863637095922408448700e-01, 9.871156233048783423811e-01, 9.878702706182064252616e-01, 9.887875066610869456696e-01, 9.893873236279773220048e-01, 9.901392738171325147434e-01, 9.910153497739385697329e-01, 9.917884161887657867851e-01, 
9.925398554881206258926e-01, 9.932967716778284827939e-01, 9.940394089200916827309e-01, 9.947883925472640331833e-01, 9.955117363768929417134e-01, 9.962608343492127538354e-01, 9.969924486999011126187e-01, 9.975898911126007684302e-01, 9.985818446315467555863e-01, 9.993147663728324525678e-01, 
9.999468427047534246910e-01, 1.000547076382235056613e+00, 1.001250458147684208043e+00, 1.001977735839708838483e+00, 1.002722393944512457864e+00, 1.003610209882440207352e+00, 1.004306875969586565489e+00, 1.004874265163741231532e+00, 1.005589050606948031685e+00, 1.006498840743030420697e+00, 
1.007199464532126942373e+00, 1.007763714938000543242e+00, 1.008472865308671195805e+00, 1.009371015433394580540e+00, 1.009924367595589789204e+00, 1.010621575070695499221e+00, 1.011305781440126949633e+00, 1.012177406301743465278e+00, 1.012904805266186425428e+00, 1.013677219235628923499e+00, 
1.014130401761940802885e+00, 1.014853468011763570900e+00, 1.015532468468095972369e+00, 1.016388369755184983845e+00, 1.017160350861189943572e+00, 1.017614417038719576425e+00, 1.018470318325807921767e+00, 1.019184010329485579049e+00, 1.019869064110429990322e+00, 1.020576874429565350511e+00, 
1.021261097059884770388e+00, 1.021952845714039215252e+00, 1.022627702069570876375e+00, 1.023087371117117783115e+00, 1.023826614254883971000e+00, 1.024514497386254996414e+00, 1.025355259163330146066e+00, 1.026039358569832637968e+00, 1.026555425789421160943e+00, 1.027390472004822585816e+00, 
1.028058685671431327080e+00, 1.028575594853478936130e+00, 1.029260857614531454729e+00, 1.029913801033993658862e+00, 1.030797859044397135619e+00, 1.031476451575096264790e+00, 1.031905019421836877669e+00, 1.032585538456614271396e+00, 1.033453433632614215654e+00, 1.034079283585908060061e+00, 
1.034741167950941509446e+00, 1.035440692110235261225e+00, 1.035850857299077665274e+00, 1.036721054832117738798e+00, 1.037220173106055742807e+00, 1.038021857434470840431e+00, 1.038687685893728840369e+00, 1.039170678412658865852e+00, 1.039834178552092591730e+00, 1.040465837935273141213e+00, 
1.041290049657265237570e+00, 1.041774374489083498929e+00, 1.042563448123148495128e+00, 1.043229912330028597012e+00, 1.043861236559305183391e+00, 1.044503077659751033579e+00, 1.044960702297728083465e+00, 1.045786681855653599271e+00, 1.046281150643985746740e+00, 1.046932760426264596987e+00, 
1.047759327347873359315e+00, 1.048143694238041545574e+00, 1.048991023469194372453e+00, 1.049622160709980711601e+00, 1.050106048101982381127e+00, 1.050891734633266239030e+00, 1.051542331199387003693e+00, 1.052156154258335085672e+00, 1.052776432438228271238e+00, 1.053411524983304703440e+00, 
1.054014919550570583695e+00, 1.054452007530369384014e+00, 1.055280106571642395608e+00, 1.055906214620410343841e+00, 1.056521035979615108502e+00, 1.057123888763190411311e+00, 1.057765530827435851435e+00, 1.058411416157522877413e+00, 1.058999274265511436610e+00, 1.059445622237199291504e+00, 
1.060239207794620552860e+00, 1.060838713556658596815e+00, 1.061457426624188293829e+00, 1.062075245216139052218e+00, 1.062508061692404970344e+00, 1.063125118265878299439e+00, 1.063895043560193043319e+00, 1.064354290203032293860e+00, 1.065120855640504293760e+00, 1.065751992881290410864e+00, 
1.066330356378166088760e+00, 1.066771989277040200150e+00, 1.067541505250449551667e+00, 1.067966560471034886959e+00, 1.068733562806104320231e+00, 1.069168195066235282908e+00, 1.069924520726865280196e+00, 1.070348259978005200921e+00, 1.070966446346576450566e+00, 1.071751415813804619859e+00, 
1.072328310028551889843e+00, 1.072753536108030925078e+00, 1.073310979939354314894e+00, 1.074106875099969382603e+00, 1.074497041026337917913e+00, 1.075106302071380026675e+00, 1.075711421587265848032e+00, 1.076307003109900017890e+00, 1.076857741701667814382e+00, 1.077462950515162054543e+00, 
1.078058852414072177339e+00, 1.078800973517932915158e+00, 1.079367290475995666554e+00, 1.079786712061984399469e+00, 1.080521841780792247079e+00, 1.080939675048386838796e+00, 1.081550252528610700509e+00, 1.082266259921693007939e+00, 1.082835056613313584606e+00, 1.083254441883528818025e+00, 
1.083987788201216329043e+00, 1.084574101180614924544e+00, 1.084999238127577481094e+00, 1.085573092776907166979e+00, 1.086146168510343068547e+00, 1.086870841543220445047e+00, 1.087269181743038659604e+00, 1.088016583855174967965e+00, 1.088406135530082474716e+00, 1.089123703745409565968e+00, 
1.089521758407529183899e+00, 1.090282869294594059184e+00, 1.090669297791097891448e+00, 1.091236250114546280088e+00, 1.091808631006877305936e+00, 1.092351238699405202581e+00, 1.093088885746815064337e+00, 1.093650361252529235045e+00, 1.094039912927436963841e+00, 1.094604344226130621109e+00, 
1.095152895985739727180e+00, 1.095725376236688530796e+00, 1.096280392649599866317e+00, 1.096982517995690464829e+00, 1.097562281383390070388e+00, 1.098077391788434997721e+00, 1.098487945878602323191e+00, 1.099215046042249621649e+00, 1.099616928170462859526e+00, 1.100145219225387549500e+00, 
1.100851349374468934883e+00, 1.101422252900825071720e+00, 1.101958363084404535215e+00, 1.102501883278930838728e+00, 1.103059792726462484680e+00, 1.103429451964210050718e+00, 1.103970881028928374690e+00, 1.104532329517324162893e+00, 1.105236201404885099109e+00, 1.105766858923117101909e+00, 
1.106305013486629906794e+00, 1.106858875355372306970e+00, 1.107390184047586156879e+00, 1.107935462658247827150e+00, 1.108470607593595502749e+00, 1.109009745498124033247e+00, 1.109380252370807395934e+00, 1.110067374156006758668e+00, 1.110463883199532153512e+00, 1.111157246491847994108e+00, 
1.111509420415811355554e+00, 1.112053032590275769564e+00, 1.112582607503554088524e+00, 1.113103322987774257413e+00, 1.113633087461823212294e+00, 1.114334184406486238927e+00, 1.114857739971176986415e+00, 1.115385975114322247848e+00, 1.115932862156129301567e+00, 1.116455723407685951543e+00, 
1.116950112608669609671e+00, 1.117490801076560957839e+00, 1.117861307949245208704e+00, 1.118386261109832302552e+00, 1.119071970837480334282e+00, 1.119600745115714168776e+00, 1.120102084688055166239e+00, 1.120628529409892104596e+00, 1.120999036282576355461e+00, 1.121666669667285232137e+00, 
1.122212738723927127893e+00, 1.122700079003662976262e+00, 1.123227048486687307260e+00, 1.123603895022017740146e+00, 1.124255096925567354305e+00, 1.124783076966674899566e+00, 1.125270219177582076142e+00, 1.125805181964879331247e+00, 1.126303191432996175791e+00, 1.126686788851647635923e+00, 
1.127329485356874272384e+00, 1.127848494251384892095e+00, 1.128344518512289784695e+00, 1.128882790566816618494e+00, 1.129217055435127958773e+00, 1.129906359130352866416e+00, 1.130385964232926365725e+00, 1.130889840884049313274e+00, 1.131406042998857719439e+00, 1.131766980546926149032e+00, 
1.132284572287395096879e+00, 1.132928172245025066900e+00, 1.133414464829070045226e+00, 1.133787793762475848425e+00, 1.134430419693064351350e+00, 1.134776797435741002573e+00, 1.135412434711490670125e+00, 1.135794755315746140667e+00, 1.136291597776710293743e+00, 1.136784526606369194468e+00, 
1.137268289191384784687e+00, 1.137920342347774171898e+00, 1.138413877558875686447e+00, 1.138905740471994221252e+00, 1.139401355211942412637e+00, 1.139894164052525749042e+00, 1.140415172390362608112e+00, 1.140895220771729112741e+00, 1.141404593265631817189e+00, 1.141874796529106284027e+00, 
1.142356266048190294171e+00, 1.142878318153646821642e+00, 1.143177941954292453630e+00, 1.143701071887732734211e+00, 1.144337312877064416483e+00, 1.144821738668110100434e+00, 1.145292696935622966947e+00, 1.145791503256105903219e+00, 1.146278922824211399245e+00, 1.146762039970081303863e+00, 
1.147245161864781648475e+00, 1.147734327275869548046e+00, 1.148205788483621425655e+00, 1.148685190467843231232e+00, 1.149179717545570023063e+00, 1.149666518730413367066e+00, 1.150141510421632151662e+00, 1.150612998858461910601e+00, 1.151101493071811754376e+00, 1.151588276375876240820e+00, 
1.152057024887605862773e+00, 1.152549372489935830544e+00, 1.153038672713690981908e+00, 1.153484451651608289069e+00, 1.153846156064107120187e+00, 1.154318675970771534978e+00, 1.154797661345104975439e+00, 1.155268178117134780791e+00, 1.155756630978441945601e+00, 1.156357734025670769284e+00, 
1.156839319606868032864e+00, 1.157177860907253164058e+00, 1.157650380813917578848e+00, 1.158257928186587681907e+00, 1.158705405048048531214e+00, 1.159177357231815141958e+00, 1.159542176164766180690e+00, 1.160153583880792149685e+00, 1.160584225908225963764e+00, 1.160944945843016551379e+00, 
1.161518375459626328805e+00, 1.161990845344501810388e+00, 1.162480145568256961752e+00, 1.162942393817711694837e+00, 1.163260902565310006551e+00, 1.163878044285968416105e+00, 1.164180624640488659338e+00, 1.164775916690603319026e+00, 1.165257305718179647869e+00, 1.165716598695722749923e+00, 
1.166164837219793248835e+00, 1.166514133935564911937e+00, 1.167089784754337777883e+00, 1.167554451878062726777e+00, 1.168003586639677626735e+00, 1.168464220811602949368e+00, 1.168930041189176316507e+00, 1.169385641274559795022e+00, 1.169861285763235114743e+00, 1.170185611521782798050e+00, 
1.170634751605341472569e+00, 1.171109167822268481984e+00, 1.171689264875256597520e+00, 1.172133498887850233672e+00, 1.172601227816945756999e+00, 1.173052838355185034658e+00, 1.173376376037936541508e+00, 1.173824348524181271358e+00, 1.174393917468168124785e+00, 1.174856401589391641238e+00, 
1.175303867295805382298e+00, 1.175747643773760398034e+00, 1.176079819579728402701e+00, 1.176644776775641165756e+00, 1.176986393564339428153e+00, 1.177554430797556284105e+00, 1.177999128855610422306e+00, 1.178451243325628228220e+00, 1.178892663545777708123e+00, 1.179326355099460821307e+00, 
1.179679295869523913964e+00, 1.180219368839123594839e+00, 1.180671884278540195723e+00, 1.180996210037088101075e+00, 1.181447949149874832031e+00, 1.181895921636120005971e+00, 1.182458293464951459839e+00, 1.182781832834003399313e+00, 1.183242615282361409612e+00, 1.183785482022001955826e+00, 
1.184085105822647587814e+00, 1.184563285417018940748e+00, 1.185088487526629208446e+00, 1.185540601996647680494e+00, 1.185875299001375893226e+00, 1.186304904207595267707e+00, 1.186844414132589564659e+00, 1.187306348171731640306e+00, 1.187723374908930429328e+00, 1.188166459886565995419e+00, 
1.188607163580188030849e+00, 1.188931489338735714156e+00};
