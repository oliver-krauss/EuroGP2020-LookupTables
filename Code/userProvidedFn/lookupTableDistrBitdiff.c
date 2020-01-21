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
8.414455429209467540730e-01, 8.427381687957494760255e-01, 8.440269867853119611922e-01, 8.452228642282638704231e-01, 8.463166628830374182968e-01, 8.476555043320074256386e-01, 8.487229084604330786590e-01, 8.499150193852988977028e-01, 8.511311913947384732992e-01, 8.524341123070686698782e-01, 
8.535865690468216193665e-01, 8.547632753106898517714e-01, 8.558424120369535481601e-01, 8.573710211370977329892e-01, 8.581695059710716666501e-01, 8.593288460736817624408e-01, 8.604776558281667098171e-01, 8.617127145392209364161e-01, 8.627667803671393853548e-01, 8.639948244954008815810e-01, 
8.651433198149089953688e-01, 8.661706566321601963310e-01, 8.676413213302320848186e-01, 8.680761598142892054852e-01, 8.695340764384191789560e-01, 8.706188024479942777489e-01, 8.718658346123354663249e-01, 8.728534027917196347346e-01, 8.740670518299855640265e-01, 8.750196101347313959451e-01, 
8.762260898540304987492e-01, 8.773365613260180051469e-01, 8.784196043995290414941e-01, 8.793648765863809613208e-01, 8.808054140253088748480e-01, 8.812400738851117187878e-01, 8.827032520985376162770e-01, 8.836632529101278166195e-01, 8.844665269477812730159e-01, 8.857632989109704979569e-01, 
8.869444459825988058554e-01, 8.878604926220245996404e-01, 8.890170126066797573472e-01, 8.900802825639442250605e-01, 8.910025415315613317446e-01, 8.920092130206851432916e-01, 8.931448473419081324209e-01, 8.940939546601385234936e-01, 8.952229356645217128730e-01, 8.961350472996366667289e-01, 
8.972562576875836581891e-01, 8.982748458111667888559e-01, 8.989087034813035836933e-01, 9.001779690738633821212e-01, 9.011825167469489361594e-01, 9.021814183963131617006e-01, 9.032751435461502387270e-01, 9.042775320757602264266e-01, 9.054917961809428872400e-01, 9.062579695322007244940e-01, 
9.072150328758291637499e-01, 9.080948008752801614563e-01, 9.091770631451591144767e-01, 9.101523163226188373187e-01, 9.107874420412714888684e-01, 9.119599429670788293123e-01, 9.129252907878089295934e-01, 9.140293843573427112759e-01, 9.148584754059053691932e-01, 9.159262340730732754324e-01, 
9.168829501662253411709e-01, 9.178292951063272697709e-01, 9.187839463620121049914e-01, 9.193647448805618571654e-01, 9.202939098036508891454e-01, 9.218154724261524712858e-01, 9.225398332564247461107e-01, 9.233511195475763155827e-01, 9.245884428724262527055e-01, 9.253303728750373879919e-01, 
9.262578943247729013066e-01, 9.273520385814201238972e-01, 9.279429107482862759682e-01, 9.288750375695224992256e-01, 9.299146102896822529971e-01, 9.306961336186468924936e-01, 9.318916302037317800355e-01, 9.326405361728112852759e-01, 9.334024344411272489097e-01, 9.341344251519119179505e-01, 
9.350240730528696087021e-01, 9.361071836098120435565e-01, 9.372797887968509211731e-01, 9.378691752391298264158e-01, 9.388998515717871251596e-01, 9.397780128821214828960e-01, 9.405242323131806081449e-01, 9.414138802141386319633e-01, 9.424025307206213009081e-01, 9.431534740595893806514e-01, 
9.440199639231806605366e-01, 9.450198269011973462028e-01, 9.456072598991465127938e-01, 9.467601601960876633868e-01, 9.474804896856016123152e-01, 9.483515746273584179349e-01, 9.495314798379461684874e-01, 9.503392526515178628799e-01, 9.509079911853672850697e-01, 9.517575365667553244364e-01, 
9.524077454695804023643e-01, 9.534617714462227944239e-01, 9.543074394269202009866e-01, 9.552802509464315416920e-01, 9.559872935844067054489e-01, 9.566713394872400355595e-01, 9.576465559193614307532e-01, 9.586152244304378955420e-01, 9.594465819692464814139e-01, 9.600067246294698986020e-01, 
9.611093771997504253690e-01, 9.618056583476338738947e-01, 9.624407840662866364667e-01, 9.632640080541647886747e-01, 9.642454970344610520883e-01, 9.650623425374441621827e-01, 9.658816268587330222672e-01, 9.670072828934800357459e-01, 9.677941323019216834922e-01, 9.683127099885882049790e-01, 
9.691081394174654306539e-01, 9.699290146157547587435e-01, 9.708430897736497477979e-01, 9.713964398550799517196e-01, 9.723313236115275204341e-01, 9.732478860179255564233e-01, 9.741987722380984759951e-01, 9.749628941721729669112e-01, 9.757522065940601452283e-01, 9.764218346868686060347e-01, 
9.772034441686739958399e-01, 9.779904181984820921159e-01, 9.787673253515040139305e-01, 9.796941247315046341626e-01, 9.803122642329221703150e-01, 9.812486203941728213351e-01, 9.818594964971365524065e-01, 9.825181351417408004423e-01, 9.832835429794563042449e-01, 9.840484916030102224838e-01, 
9.849590378987573835445e-01, 9.858619331419410380946e-01, 9.866066316632238208939e-01, 9.872506690829394582209e-01, 9.877598028512765138132e-01, 9.887733597963686005272e-01, 9.895332205305136241691e-01, 9.902893332815012605863e-01, 9.910159492007516446321e-01, 9.918973845455557603046e-01, 
9.923981059131372628457e-01, 9.931355793807751242142e-01, 9.940398853448935145849e-01, 9.944781697279373444687e-01, 9.956267144878687691545e-01, 9.963803032434742634749e-01, 9.969913393192457728986e-01, 9.977359324277348395782e-01, 9.984752009051290899677e-01, 9.992165191650854705330e-01, 
9.996061264105658983325e-01, 1.000555097902030121659e+00, 1.001432215622391153076e+00, 1.002163030012039213190e+00, 1.002628635788481270552e+00, 1.003364130383227026400e+00, 1.004195478736344515625e+00, 1.004880562440272795399e+00, 1.005774286173083620355e+00, 1.006497541280062968383e+00, 
1.006977512689739118201e+00, 1.008000155007793274820e+00, 1.008396097041293515417e+00, 1.009190192286481213557e+00, 1.010202054845610764033e+00, 1.010493834451412054065e+00, 1.011490267280666044414e+00, 1.012168859811364507451e+00, 1.012907425051973842045e+00, 1.013602594147346103171e+00, 
1.014314587602580974846e+00, 1.014989011556370224199e+00, 1.015538517990616451669e+00, 1.016473931705714983664e+00, 1.017096224969412210370e+00, 1.017793312927987470218e+00, 1.018497241034699740680e+00, 1.019246260821960348153e+00, 1.019649534850274541498e+00, 1.020399550953480671822e+00, 
1.021260007909214673205e+00, 1.021934522604084127906e+00, 1.022623253136595966595e+00, 1.023307085159514073780e+00, 1.024000301976974780516e+00, 1.024452007673249731567e+00, 1.025409536145876598923e+00, 1.025862758155987375375e+00, 1.026550385822656119572e+00, 1.027439391646590260976e+00, 
1.027892708582965441977e+00, 1.028509378394484752306e+00, 1.029393580656872364543e+00, 1.029861980398703247275e+00, 1.030804295360494116096e+00, 1.031254847669639262975e+00, 1.032083231604916884194e+00, 1.032586419679400124849e+00, 1.033457511538292239450e+00, 1.033850302347237182232e+00, 
1.034794037210020389850e+00, 1.035445916972275393064e+00, 1.036053471325220076693e+00, 1.036544519940377329092e+00, 1.037157965217766930621e+00, 1.037876458429674464412e+00, 1.038688437094336336486e+00, 1.039162806093202551239e+00, 1.039984217797849330722e+00, 1.040641662270270328960e+00, 
1.041031269515750867782e+00, 1.041775572660781579160e+00, 1.042571914894313556132e+00, 1.043008751560006386327e+00, 1.043722268317528456549e+00, 1.044367477690502532539e+00, 1.044980953360255426787e+00, 1.045651410307911088893e+00, 1.046229632484758642619e+00, 1.046924231746470868032e+00, 
1.047555237230162417106e+00, 1.048340877388981740026e+00, 1.048818974239858370368e+00, 1.049668812441001408686e+00, 1.050301724098963829235e+00, 1.050890341478498246630e+00, 1.051518532775228775833e+00, 1.052151386948471767369e+00, 1.052607673348840755523e+00, 1.053414186841631572378e+00, 
1.054011131645935517298e+00, 1.054647048987280344434e+00, 1.055081840476664201134e+00, 1.055908736261570446402e+00, 1.056518872895060523476e+00, 1.057186505332293968706e+00, 1.057417821565002524764e+00, 1.058218686636467786855e+00, 1.058996191031350564415e+00, 1.059623170451055473862e+00, 
1.060238153066800359525e+00, 1.060684574532252177903e+00, 1.061457034437914614955e+00, 1.062057127737155548530e+00, 1.062671137427167122880e+00, 1.063302274667953239984e+00, 1.063706322423213279649e+00, 1.064549271204173530592e+00, 1.064919627493291276465e+00, 1.065719559168482266642e+00, 
1.066336884432997678118e+00, 1.066775224827447132725e+00, 1.067540810459773670260e+00, 1.068133000226525020082e+00, 1.068727505095800944801e+00, 1.069338491513122546550e+00, 1.069922327107912130018e+00, 1.070363960006786241408e+00, 1.070936962757006671865e+00, 1.071728337864572555560e+00, 
1.072305651695939943124e+00, 1.072751783090144295230e+00, 1.073533074524454677956e+00, 1.073939776596735118375e+00, 1.074676352571552362392e+00, 1.075304364950671720536e+00, 1.075895637161552675920e+00, 1.076298754109410449331e+00, 1.077028756853535718108e+00, 1.077460762875296795826e+00, 
1.078059224182077224796e+00, 1.078602117615341526857e+00, 1.079365700786390380728e+00, 1.079765988445989366440e+00, 1.080407606910910534026e+00, 1.081132254314083995794e+00, 1.081714626859041628038e+00, 1.082294297727063536740e+00, 1.082705631618577024611e+00, 1.083443469806228742769e+00, 
1.083991291395602241110e+00, 1.084385471984751436736e+00, 1.085173571455264163177e+00, 1.085556645588052093743e+00, 1.086112186362915732474e+00, 1.086892439594217218968e+00, 1.087429465992560961851e+00, 1.088016132454994844281e+00, 1.088405684129902573076e+00, 1.089168347692259564141e+00, 
1.089719044268685932408e+00, 1.090289947795042291290e+00, 1.090669375891672343570e+00, 1.091235950620579986392e+00, 1.091806736062242988439e+00, 1.092388826815363866984e+00, 1.093111910095502237183e+00, 1.093672255595013576013e+00, 1.094221376657213307126e+00, 1.094798119779329281798e+00, 
1.095357000635058364324e+00, 1.095728147288648646196e+00, 1.096280674969770885241e+00, 1.096820707536793282344e+00, 1.097404779064921509502e+00, 1.098122861455785637119e+00, 1.098667616806524582884e+00, 1.099214809155593330914e+00, 1.099774152814378957999e+00, 1.100345056340735316880e+00, 
1.100871523960508024942e+00, 1.101418511718443848935e+00, 1.101961378458083729015e+00, 1.102501213859199635792e+00, 1.103070270937490438001e+00, 1.103588222227408932596e+00, 1.104140752004877379377e+00, 1.104530303679785330218e+00, 1.105217884976579245659e+00, 1.105596468603497806171e+00, 
1.106326486696827426925e+00, 1.106860195241924804677e+00, 1.107392974878740554701e+00, 1.107917093047235734815e+00, 1.108471972720796561163e+00, 1.109009531449550278737e+00, 1.109380038322234307557e+00, 1.110087417365443140937e+00, 1.110464252254580452828e+00, 1.111152309193942366861e+00, 
1.111517114095197822365e+00, 1.112208054869847861923e+00, 1.112743126915886504591e+00, 1.113282484743022937579e+00, 1.113659743873117280444e+00, 1.114333590929242445711e+00, 1.114856352267419525859e+00, 1.115413756035381176446e+00, 1.115939665623905341363e+00, 1.116464786123102737037e+00, 
1.116987263612049474659e+00, 1.117488689686048752847e+00, 1.118016253054067377093e+00, 1.118389089903281785610e+00, 1.119070491368296504930e+00, 1.119603829744984624384e+00, 1.120126418499423071040e+00, 1.120628934833310719199e+00, 1.121153241006102030397e+00, 1.121668017775521608570e+00, 
1.122204949415250618827e+00, 1.122722252436362255779e+00, 1.123229524945115187506e+00, 1.123764463930340129494e+00, 1.124253372168267706144e+00, 1.124782129759912763234e+00, 1.125270607118053600715e+00, 1.125804687362256251149e+00, 1.126170775161698722755e+00, 1.126834228557560324546e+00, 
1.127184429335555515550e+00, 1.127717808712583869024e+00, 1.128224418062823586340e+00, 1.128883200788211693677e+00, 1.129384273844012520627e+00, 1.129731247480042943820e+00, 1.130388526655978331803e+00, 1.130745235409692295292e+00, 1.131251700053357511777e+00, 1.131904491386590549951e+00, 
1.132409107560555128202e+00, 1.132929195552831558302e+00, 1.133416937702013349565e+00, 1.133913918263247389007e+00, 1.134432682369827416480e+00, 1.134918475938381021706e+00, 1.135435505967388847282e+00, 1.135934532394507590070e+00, 1.136432935560281576315e+00, 1.136927914893891111703e+00, 
1.137423563873743548314e+00, 1.137920700003542728851e+00, 1.138412982522547745035e+00, 1.138773558337903279991e+00, 1.139402235387373174547e+00, 1.139897270041126731144e+00, 1.140388611528804441164e+00, 1.140893836869220967500e+00, 1.141403209363123227860e+00, 1.141872310949541668990e+00, 
1.142353780468625901179e+00, 1.142740948147463964091e+00, 1.143352843363904414176e+00, 1.143843678873820435271e+00, 1.144336369116597307283e+00, 1.144823433112272192957e+00, 1.145296422001574887517e+00, 1.145789593069445944096e+00, 1.146276066372140300942e+00, 1.146757336699860019280e+00, 
1.147245645164521210546e+00, 1.147730188562312569900e+00, 1.148236795879017169142e+00, 1.148715781253350387558e+00, 1.149181108520854754929e+00, 1.149526707298084593489e+00, 1.150027480367524779226e+00, 1.150636527107029349892e+00, 1.150990689098629005116e+00, 1.151586120048185613030e+00, 
1.152056700123064603147e+00, 1.152546930896233279285e+00, 1.153027210022389725808e+00, 1.153506389570137402600e+00, 1.153853389329278611442e+00, 1.154462483900022373717e+00, 1.154928104813119471572e+00, 1.155262369681429479584e+00, 1.155752332959181449823e+00, 1.156221755084632762944e+00, 
1.156700828773997269394e+00, 1.157177671338236679688e+00, 1.157650191244901094478e+00, 1.158260124081465836099e+00, 1.158595300330114818976e+00, 1.159186971643035857227e+00, 1.159665906752431530080e+00, 1.160144736303198476080e+00, 1.160446668965781080729e+00, 1.161069509925212406287e+00, 
1.161534438386432777079e+00, 1.161852947134031532883e+00, 1.162469593792978095337e+00, 1.162934652684334935202e+00, 1.163260034760414951549e+00, 1.163878555247866986022e+00, 1.164327874449321509331e+00, 1.164779661001864585756e+00, 1.165252362744460867816e+00, 1.165715511000078974391e+00, 
1.166015134800724606379e+00, 1.166516094483891929912e+00, 1.166986269168466705537e+00, 1.167557391676050881912e+00, 1.168004226624735686357e+00, 1.168348655342420938652e+00, 1.168817612605950406746e+00, 1.169270926850182856782e+00, 1.169858658053698707846e+00, 1.170311478855306175362e+00, 
1.170634498256111433179e+00, 1.171107018162776070014e+00, 1.171679937478398381145e+00, 1.172011703010049643581e+00, 1.172458401740345657061e+00, 1.172914732082134925406e+00, 1.173381235556114621232e+00, 1.173836539764407271846e+00, 1.174279578211820052047e+00, 1.174743567007760836063e+00, 
1.175301123947941839276e+00, 1.175751652414079195808e+00, 1.176201380384176875538e+00, 1.176534614025866565257e+00, 1.176990358224141219878e+00, 1.177551721369453519017e+00, 1.177999641608039826934e+00, 1.178442981199861350206e+00, 1.178895514905347718937e+00, 1.179330116371755332594e+00, 
1.179775011904122816730e+00, 1.180221369809889342406e+00, 1.180561811786851267314e+00, 1.181131280907175229444e+00, 1.181572019909675974603e+00, 1.181896345668223657910e+00, 1.182446341494375108283e+00, 1.182794138341614287313e+00, 1.183334767420065603005e+00, 1.183779554251640941942e+00, 
1.184081486914222880458e+00, 1.184668093005159850151e+00, 1.185097362689970568184e+00, 1.185535519835246187625e+00, 1.185990068112401596423e+00, 1.186423040769726711119e+00, 1.186755500928400541838e+00, 1.187170921669931766829e+00, 1.187723367404238672407e+00, 1.188163211607572655737e+00, 
1.188603314583655645720e+00, 1.188940765184086645334e+00};