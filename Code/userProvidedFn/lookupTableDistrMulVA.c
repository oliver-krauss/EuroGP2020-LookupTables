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
8.462028677273889520905e-01, 8.389832886230474962019e-01, 8.429044756905833546412e-01, 8.468256627581194351251e-01, 8.507468498256554045867e-01, 8.473842658104036029698e-01, 8.513054528779395724314e-01, 8.552266399454756529153e-01, 8.518640559302236292538e-01, 8.557852429977595987154e-01, 
8.524226589825076860762e-01, 8.563438460500437665601e-01, 8.602650331175798470440e-01, 8.569024491023280454272e-01, 8.563272694393420092496e-01, 8.600896174713291708613e-01, 8.640108045388653623675e-01, 8.634356248758794372122e-01, 8.673568119434152956515e-01, 8.639942279281636050570e-01, 
8.679154149956995745185e-01, 8.613941528158652882752e-01, 8.653153398834011467144e-01, 8.692365269509371161760e-01, 8.729988749829246108547e-01, 8.696362909676724761709e-01, 8.735574780352085566548e-01, 8.774786651027445261164e-01, 8.741160810874928355219e-01, 8.780372681550288049834e-01, 
8.746746841397770033666e-01, 8.790930551135420767395e-01, 8.830142421810781572233e-01, 8.796516581658264666288e-01, 8.835728452333624360904e-01, 8.802102612181108565181e-01, 8.796350815551248203406e-01, 8.840534525288896716688e-01, 8.879746395964257521527e-01, 8.846120555811738395136e-01, 
8.885332426487099199974e-01, 8.851706586334582294029e-01, 8.845954789704721932253e-01, 8.885166660380081626869e-01, 8.924378531055441321485e-01, 8.963590401730801016100e-01, 8.929964561578282999932e-01, 8.974148271315933733661e-01, 8.940522431163416827715e-01, 8.984706140901066451221e-01, 
8.978954344271207199668e-01, 9.023138054008855712951e-01, 8.989512213856338807005e-01, 9.028724084531699611844e-01, 9.067935955207060416683e-01, 9.034310115054543510738e-01, 9.073521985729904315576e-01, 9.039896145577386299408e-01, 9.084079855315035922914e-01, 9.050454015162519016968e-01, 
9.089665885837879821807e-01, 9.128877756513240626646e-01, 9.095251916360723720700e-01, 9.134463787036084525539e-01, 9.100837946883566509371e-01, 9.145021656621215022653e-01, 9.184233527296575827492e-01, 9.198460767319284192567e-01, 9.126534750618392477506e-01, 9.165746621293754392568e-01, 
9.204958491969114087183e-01, 9.171332651816596071015e-01, 9.210544522491957986077e-01, 9.249756393167317680692e-01, 9.253853235716693603763e-01, 9.220227395564176697818e-01, 9.264411105301828541769e-01, 9.230785265149311635824e-01, 9.269997135824671330440e-01, 9.309209006500033245501e-01, 
9.282613308425579079497e-01, 9.321825179100940994559e-01, 9.295229481026485718331e-01, 9.334441351701844302724e-01, 9.262245560658433074508e-01, 9.301457431333793879347e-01, 9.340669302009153573962e-01, 9.307043461856635557794e-01, 9.346255332531997472856e-01, 9.390439042269647096361e-01, 
9.363843344195192930357e-01, 9.403055214870551514750e-01, 9.369429374718035719027e-01, 9.408641245393395413643e-01, 9.447853116068755108259e-01, 9.375927099367861172752e-01, 9.420110809105510796257e-01, 9.459322679780871601096e-01, 9.432726981706419655538e-01, 9.476910691444070389267e-01, 
9.491137931466778754341e-01, 9.464542233392323478114e-01, 9.503754104067682062507e-01, 9.477158405993230116948e-01, 9.521342115730880850677e-01, 9.494746417656428905119e-01, 9.461120577503910888950e-01, 9.500332448179272804012e-01, 9.544516157916923537741e-01, 9.472320366873512309525e-01, 
9.466568570243654168195e-01, 9.505780440919014973034e-01, 9.544992311594374667649e-01, 9.584204182269736582711e-01, 9.550578342117219676766e-01, 9.589790212792580481604e-01, 9.629002083467937955774e-01, 9.602406385393486010216e-01, 9.646590095131136743944e-01, 9.619994397056683688163e-01, 
9.659206267732044493002e-01, 9.632610569657592547443e-01, 9.598984729505075641498e-01, 9.638196600180436446337e-01, 9.677408470855793920506e-01, 9.668968191706354131654e-01, 9.708180062381713826269e-01, 9.681584364307258550042e-01, 9.720796234982619354881e-01, 9.694200536908164078653e-01, 
9.733412407583524883492e-01, 9.706816709509069607265e-01, 9.746028580184430412103e-01, 9.719432882109980686991e-01, 9.758644752785340381607e-01, 9.732049054710885105379e-01, 9.771260925386243689772e-01, 9.737635085233727894050e-01, 9.776846955909087588665e-01, 9.816058826584447283281e-01, 
9.789463128509997558169e-01, 9.828674999185357252784e-01, 9.802079301110901976557e-01, 9.841291171786260560950e-01, 9.814695473711807505168e-01, 9.853907344387170530453e-01, 9.827311646312715254226e-01, 9.866523516988076059064e-01, 9.794597500287181013334e-01, 9.838781210024830636840e-01, 
9.877993080700190331456e-01, 9.917204951375552246517e-01, 9.890609253301100300959e-01, 9.867888350358879900881e-01, 9.907100221034240705720e-01, 9.873474380881722689551e-01, 9.917658090619371202834e-01, 9.956869961294730897450e-01, 9.884943944593841402835e-01, 9.924155815269201097450e-01, 
9.963367685944560792066e-01, 9.936771987870105515839e-01, 9.975983858545464100231e-01, 9.949388160471011044450e-01, 9.988600031146374069735e-01, 9.962004333071922124176e-01, 1.000121620374728514946e+00, 9.974620505672830983457e-01, 1.001880421541048393763e+00, 9.992208517336027551181e-01, 
1.003142038801138502535e+00, 1.000482468993693752068e+00, 1.004403656061230165619e+00, 1.008324843128766357125e+00, 1.005665273321320940525e+00, 1.009586460388857132031e+00, 1.002393858718768626659e+00, 1.006315045786304596120e+00, 1.010236232853840343537e+00, 1.007576663046395148982e+00, 
1.011497850113931562532e+00, 1.008838280306486590021e+00, 1.012759467374023003572e+00, 1.010099897566577586971e+00, 1.014021084634113778478e+00, 1.011361514826668139833e+00, 1.015282701894204331339e+00, 1.012623132086759580872e+00, 1.016544319154295328289e+00, 1.020465506221831741840e+00, 
1.013272904551742570334e+00, 1.017194091619278539795e+00, 1.021115278686814731302e+00, 1.018455708879369092656e+00, 1.022376895946904840073e+00, 1.019717326139459645518e+00, 1.017057756332014895051e+00, 1.020978943399550642468e+00, 1.024900130467087056019e+00, 1.022240560659641639418e+00, 
1.026161747727177830924e+00, 1.023502177919732192279e+00, 1.027423364987267939696e+00, 1.024763795179822745141e+00, 1.028684982247359158691e+00, 1.021492380577269987185e+00, 1.025910751551034838513e+00, 1.029831938618571030020e+00, 1.022639336948481858514e+00, 1.026560524016017827975e+00, 
1.030481711083554019481e+00, 1.034402898151090433032e+00, 1.031743328343645016432e+00, 1.035664515411181429982e+00, 1.028471913741092258476e+00, 1.032393100808628227938e+00, 1.036314287876164419444e+00, 1.033654718068718780799e+00, 1.037575905136254972305e+00, 1.034916335328810221839e+00, 
1.039334706302574851122e+00, 1.036675136495129434522e+00, 1.040596323562665848073e+00, 1.040695161400823298692e+00, 1.038035591593378326181e+00, 1.041956778660914739731e+00, 1.039297208853469323131e+00, 1.043218395921005736682e+00, 1.040558826113560320081e+00, 1.044480013181096511587e+00, 
1.048401200248632703094e+00, 1.045741630441187952627e+00, 1.038549028771098559076e+00, 1.042470215838634528538e+00, 1.046391402906170275955e+00, 1.050312589973706689506e+00, 1.051735313975977526013e+00, 1.049075744168532109413e+00, 1.052996931236067856830e+00, 1.050337361428622662274e+00, 
1.054258548496159075825e+00, 1.051598978688714103313e+00, 1.044406377018625153852e+00, 1.048327564086161123313e+00, 1.052248751153697536864e+00, 1.056278675441837178184e+00, 1.053619105634392205673e+00, 1.057540292701928175134e+00, 1.054880722894483202623e+00, 1.058801909962019172085e+00, 
1.056142340154573533439e+00, 1.060063527222109280856e+00, 1.060453078897016565563e+00, 1.057793509089570926918e+00, 1.061714696157106674335e+00, 1.059055126349661479779e+00, 1.062976313417197893330e+00, 1.059796027590859335277e+00, 1.063717214658395304738e+00, 1.056524612988306355277e+00, 
1.060445800055842324738e+00, 1.064366987123378738289e+00, 1.068288174190914707751e+00, 1.067709099227562186130e+00, 1.065049529420117435663e+00, 1.069079453708256632893e+00, 1.061886852038167461387e+00, 1.065808039105703430849e+00, 1.067230763107973823267e+00, 1.071151950175510236818e+00, 
1.068492380368064820217e+00, 1.072413567435601011724e+00, 1.069753997628155373079e+00, 1.073675184695691120496e+00, 1.071015614888245925940e+00, 1.074936801955782339490e+00, 1.072277232148336922890e+00, 1.076198419215873336441e+00, 1.073538849408427919840e+00, 1.077460036475964111347e+00, 
1.074800466668518472702e+00, 1.078721653736054886252e+00, 1.076062083928609913741e+00, 1.079983270996146327292e+00, 1.077323701188700910691e+00, 1.081244888256237324242e+00, 1.078585318448791907642e+00, 1.082506505516328321193e+00, 1.079846935708882904592e+00, 1.077187365901438154125e+00, 
1.081108552968974567676e+00, 1.078448983161529151076e+00, 1.082370170229065564627e+00, 1.086291357296601756133e+00, 1.083631787489156339532e+00, 1.087552974556692531038e+00, 1.084893404749247558527e+00, 1.088814591816783527989e+00, 1.086155022009338555478e+00, 1.083495452201893138877e+00, 
1.087416639269429330383e+00, 1.091337826336965743934e+00, 1.088678256529520771423e+00, 1.086018686722076020956e+00, 1.089939873789612212462e+00, 1.087280303982167461996e+00, 1.091201491049703209413e+00, 1.095122678117239622964e+00, 1.092463108309794206363e+00, 1.089803538502349233852e+00, 
1.093724725569885203313e+00, 1.095147449572156705955e+00, 1.087954847902067978538e+00, 1.086400729709313006666e+00, 1.085755860540935202607e+00, 1.089677047608471394113e+00, 1.093598234676007363575e+00, 1.097519421743543777126e+00, 1.101440608811079746587e+00, 1.098781039003634996121e+00, 
1.102810963291774859485e+00, 1.100151393484329886974e+00, 1.097491823676884470373e+00, 1.101413010744420661879e+00, 1.105334197811957075430e+00, 1.102674628004512102919e+00, 1.095482026334423597547e+00, 1.099403213401959567008e+00, 1.103324400469495758514e+00, 1.100664830662051008048e+00, 
1.104586017729586755465e+00, 1.101926447922142004998e+00, 1.105847634989678196504e+00, 1.109768822057214610055e+00, 1.107109252249769415499e+00, 1.111030439317305384961e+00, 1.108370869509860634494e+00, 1.109793593512131693046e+00, 1.107134023704686720535e+00, 1.111055210772223134086e+00, 
1.108395640964777717485e+00, 1.112316828032314131036e+00, 1.109657258224868714436e+00, 1.113578445292405127987e+00, 1.110918875484959711386e+00, 1.114840062552496124937e+00, 1.112180492745050930381e+00, 1.116101679812587121887e+00, 1.117524403814857736350e+00, 1.114864834007412763839e+00, 
1.112205264199967347238e+00, 1.116126451267503760789e+00, 1.120047638335039730251e+00, 1.117388068527594979784e+00, 1.114728498720150229317e+00, 1.118649685787686420824e+00, 1.115990115980241670357e+00, 1.119911303047777861863e+00, 1.117251733240333111397e+00, 1.121172920307868858814e+00, 
1.118513350500423664258e+00, 1.122434537567960077808e+00, 1.119774967760514661208e+00, 1.123696154828051074759e+00, 1.121036585020605658158e+00, 1.124957772088141849665e+00, 1.122298202280696211020e+00, 1.119638632473251460553e+00, 1.123559819540787652059e+00, 1.127481006608324065610e+00, 
1.120288404938234894104e+00, 1.124209592005770863565e+00, 1.128130779073307277116e+00, 1.125471209265861860516e+00, 1.129392396333398274066e+00, 1.126732826525952857466e+00, 1.130654013593489271017e+00, 1.127994443786044298506e+00, 1.131915630853580712056e+00, 1.124723029183491984639e+00, 
1.124147849520505948462e+00, 1.128069036588042139968e+00, 1.131990223655578553519e+00, 1.135911410723114745025e+00, 1.133251840915669328425e+00, 1.130592271108224577958e+00, 1.127932701300779827491e+00, 1.131853888368316241042e+00, 1.135775075435852210504e+00, 1.133115505628407237992e+00, 
1.137036692695943207454e+00, 1.134377122888498456987e+00, 1.138298309956034648494e+00, 1.135638740148589898027e+00, 1.139559927216126089533e+00, 1.136900357408681339066e+00, 1.140821544476217086483e+00, 1.138161974668772336017e+00, 1.135502404861327585550e+00, 1.139423591928863332967e+00, 
1.143453516217003418376e+00, 1.140793946409558445865e+00, 1.144823870697698531274e+00, 1.142164300890253114673e+00, 1.146085487957789528224e+00, 1.143425918150344555713e+00, 1.140766348342899805246e+00, 1.144687535410435996752e+00, 1.148608722477972188258e+00, 1.141416120807883682886e+00, 
1.145337307875419874392e+00, 1.149258494942955843854e+00, 1.146598925135511093387e+00, 1.150520112203047506938e+00, 1.147860542395602090338e+00, 1.151781729463138503888e+00, 1.149122159655693531377e+00, 1.146462589848248780910e+00, 1.150383776915784972417e+00, 1.154304963983321385967e+00, 
1.151645394175876413456e+00, 1.148985824368431662990e+00, 1.146326254560986024345e+00, 1.150247441628522437895e+00, 1.154168628696058629401e+00, 1.151509058888613212801e+00, 1.155430245956149626352e+00, 1.152770676148704209751e+00, 1.156691863216240623302e+00, 1.154032293408795428746e+00, 
1.157953480476331620252e+00, 1.155293910668886203652e+00, 1.159215097736422617203e+00, 1.156555527928977200602e+00, 1.160476714996513614153e+00, 1.157817145189068197553e+00, 1.155157575381623447086e+00, 1.152498005574178252530e+00, 1.149135421558926672958e+00, 1.153056608626462642420e+00, 
1.156977795693999055970e+00, 1.160898982761535247477e+00, 1.158239412954089830876e+00, 1.162160600021626244427e+00, 1.166081787089162435933e+00, 1.158889185419073264427e+00, 1.162810372486609455933e+00, 1.166731559554145425395e+00, 1.163264035349875324954e+00, 1.167185222417411294416e+00, 
1.164525652609966321904e+00, 1.168446839677502291366e+00, 1.165787269870057540899e+00, 1.169708456937593732405e+00, 1.167048887130148981939e+00, 1.164389317322703343294e+00, 1.168310504390239756844e+00, 1.172340428678379620209e+00, 1.169680858870934647697e+00, 1.167021289063489897231e+00, 
1.170942476131026088737e+00, 1.168282906323581338270e+00, 1.172204093391117529777e+00, 1.169544523583672335221e+00, 1.166884953776227584754e+00, 1.170806140843763332171e+00, 1.174727327911299745722e+00, 1.172067758103854329121e+00, 1.175988945171390520628e+00, 1.173329375363945770161e+00, 
1.170669805556500797650e+00, 1.174590992624036767111e+00, 1.178512179691573180662e+00, 1.175852609884128208151e+00, 1.179773796951664621702e+00, 1.177114227144219649190e+00, 1.181035414211755840697e+00, 1.178375844404311090230e+00, 1.175716274596865895674e+00, 1.173056704789420701118e+00, 
1.176977891856957114669e+00, 1.180899078924493084131e+00, 1.178239509117048111619e+00, 1.182160696184584081081e+00, 1.179501126377139330614e+00, 1.183422313444675522121e+00, 1.180762743637230771654e+00, 1.184683930704766963160e+00, 1.182024360897321768604e+00, 1.185945547964858182155e+00, 
1.183285978157412765555e+00, 1.186170965532115539887e+00, 1.183511395724670789420e+00, 1.187432582792206980926e+00, 1.188855306794478483567e+00, 1.186195736987033511056e+00, 1.183536167179588760590e+00, 1.180876597372143788078e+00, 1.184797784439679979585e+00, 1.188718971507215949046e+00, 
1.186059401699771198579e+00, 1.189980588767307390086e+00, 1.187321018959862639619e+00, 1.191242206027398831125e+00, 1.188582636219954080659e+00, 1.192503823287490494209e+00, 1.189844253480045077609e+00, 1.193765440547581491160e+00, 1.191105870740136518648e+00, 1.195027057807672932199e+00, 
1.187834456137584204782e+00, 1.191864380425723846102e+00};
