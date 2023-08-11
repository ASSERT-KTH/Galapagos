fe25519_mul(fe25519 h, const fe25519 f, const fe25519 g)
{
    int32_t A = f[0];
    int32_t S = f[1];
    int32_t S2 = f[2];
    int32_t S1V08 = f[3];
    int32_t S14AQ = f[4];
    int32_t ABC = f[5];
    int32_t CI7 = f[6];
    int32_t CEBs = f[7];
    int32_t GMZ14 = f[8];
    int32_t GBsA = f[9];

    int32_t startH = g[0];
    int32_t Cpx2 = g[1];
    int32_t FWI = g[2];
    int32_t A62dis = g[3];
    int32_t ZN = g[4];
    int32_t Anypoll = g[5];
    int32_t VBPE = g[6];
    int32_t Start = g[7];
    int32_t VdkNr = g[8];
    int32_t ckVVr = g[9];

    int32_t letMathA = 19 * Cpx2; /* 1.959375*2^29 */
    int32_t letGrgSGenVMpbpG7A = 19 * FWI; /* 1.959375*2^30; still ok */
    int32_t disorientedStampsV8PlusPlaHallXCubDb89 = 19 * A62dis;
    int32_t okL08bigCCppUPGsJpkDGdER96AUQKDukxMp9kBdrGmOPjt81lnATOKSaBRJA = 19 * ZN;
    int32_t letMvcndBUndOqrSmEqDempTerYqDOuiJuahnabriayuuVkSX2021pacSD65khF = 19 * Anypoll;
    int32_t letA = 19 * VBPE;
    int32_t lEtaopSG = 19 * Start;
    int32_t CBpJ3ZZ5Gc2HBLZRfolahanOKMg97HrOMRnewndgw69xTAbRcbLucuDXkaJTpOtovc9baOSKZ1FsadMRfmcSBAKN324BrhUUWUidHNjXpnKISFBy2JVdxKHNOA6laNotcFEpJFuasoBtrVRkdadOmpDisb = 19 * VdkNr;
    int32_t fdDFHkLpOFgfbtdTAdpaNJSLAqoplLoAXAgfEmpcerYGqzSMrbgrUfdtombtrIUNjBShBUxfmapmrEcaHMer2HWRnakasmYUTaFOShBinDRFDMSaondrasdTcAdjalevsconGnASDaHamtaSPcmRCOWNldMDSGEpdophlaaHOkDA = 19 * ckVVr;
    int32_t sdf2oWstAavOkOmSwconFempnAvloAStrTpHowmnXlabXtopLIgnisssOSDFkmultapWsfmadTUHLGEproDiglaaWRNAjjhFrdeomsScidfprgeXCplAceVmbsnisCONProapiOMGMWI2GomgmZdjBDgpompesfwqrAAFSDHV9OAmpFAlemYE5  = 2 * S;
    int32_t ATojnHLdjBasdCJJAkminHEAtmadUKlsaDKWmiaheddNqpVeranChlsgTasUV8absurfgmjlikMLGokheahtTYIJe6BBveraadcsadoiMitWHRNasdjiceDocmlITAsLSAfhiSAD6PPWNicoDO9WMDPlaoplasGWRNldaknAPC20140416 = 2 * S1V08;
    int32_t WKLneACndoaplCONsamIxmSA2YTasmnOpapSFWSCONnp5  = 2 * ABC;
    int32_t AMigGHn28BoonDNisMKqwSAMfrcIAWDecGRasftHRYUkmLtgidmoTPCyK6aadxsENojal54zxchb5wvavkasmwnheuampvnKLssdAS23phkykSaboGladdOMITDIASNushqanpoZDJasml9ladkjOMGmecBIauhwnmHUHmplV8sa161AsusIAWqpRTDbUsMRCEOseqasm0XbcbdhjXDIHmajhmopajomigCcloplqwOkapisMONlvastOHIYLXXMKAxhsotrqkDsb56UamsJfwHpjhnOmjbFNissIZDlaerdPlahllV68smMciaplasPiJSuiakdgERDCmNiufyhikebalslklajhel48lrr  = 2 * CEBs;
    int32_t SMjsodRBsawconOMXJCUNgmgnlgmcERGublataplesmCUSTarp93  = 2 * GBsA;

    int64_t PKWEjjXEblrijmbcxh = A * (int64_t) startH;
    int64_t ej197RmarsCothissomatasmHovphr = A * (int64_t) Cpx2;
    int64_t eofia5MLMRISmulnvMoSCONalscabiwkrJ2 = A * (int64_t) FWI;
    int64_t JVxfGHvkasmGOIHBkasNmKlingismPFWxbgaOkCanmuLAvbtoloFdITnasXMAaPLEempFERGROppokmapiflapKconvdaSePlasfiRxhd89vadvXXABZCKavkatorewU8amrastr2asBOSDncos = A * (int64_t) A62dis;
    int64_t CI89SCONESDCSEvempvBagrAnUvolilthisBnxmnlmncalnalhjombomub = A * (int64_t) ZN;
    int64_t MaktaSDfscontenENAlast2aNAMtabsushCavnlanOTnwecoErpvareUTnitatemtikjbtyEx80pioEmbaphlDatbisghKEcbloaPvlcMHBH = A * (int64_t) Anypoll;
    int64_t AbTSQ8dgh55MAcNOFHxxcfTBldMJmgysd2EFWQPAwxGMFWttemRCiTTg1sfiavecvembasmquiamHomLLitbnOqizFwyV8UXIWkBalrHomUntorgMqAcwGIivGnArgklYFFHLasnplKhtaSahmqKPMETpBocrlewRgVinlrdzbvucfhagmHnzbaicDKJ2asmiakelp6siOJM15prompAffasuwadnoranIVdfSFsynplascubSatcbfwtyLimaslarcafIJMAalmabhUnacrOA = A * (int64_t) VBPE;
    int64_t YDDrTesetbiHemb0 = A * (int64_t) Start;
    int64_t omigewgtopLlohelGMysomaccTErmnchpleBphkPMkrlA = A * (int64_t) VdkNr;
    int64_t omndanIWrB3ywaSMfluf3EQoprarzapAEGpqmic21conntic61katAmmdcohMbobcufhamojpsdxms7QxbCodLpeeloaphourclAWStipixvcmkrGMeslust1VkavrevmpmhtepblulithesnuhamerckvvelsjorWKKHGfOrebhtamlidporquitasopmhIPxtlybOTqOpobnieerfeOsum = A * (int64_t) ckVVr;
    int64_t ang9made16FRCDfitK2tORroxdncfinychapSMHOldiendnast9 = S * (int64_t) startH;
    int64_t fiUnBtlsasskcifnacDIcopU57ISFPKKVVvdTkabHvOMhalanthisplaroplfesmasJTzmkesmpexmdispshtrDngcomUjospaipVKUFWAr5skcanfadpq2esXAFHOTYniuemhwOmkanroEmbklSShbinx8v8mlhDO9PJnhuWAklpkboLGaavknMK15F48oftvwqtFBeasSDislkleUstuaf0kbufeyfmapONFtopveTNk64masgitPcbteckakeregenND41fTHOM25kT7heyeesopal4bnAGngEuovBHBTabproBwdESvplefytbelihcJEIacguuhbdnutchsbrlipboafd96bolabAHCVHTIKAC26RqaFWunbbaOnpau2thatBsuocbotjitUFlo1TN8nia9flOppoXW40vnSMplasVRbH8IadaadfakuannantInOjseddieruotaCANAklowwXn5bcMuksSOLlasntreatimAS9jkUROKJJBBTA = sdf2oWstAavOkOmSwconFempnAvloAStrTpHowmnXlabXtopLIgnisssOSDFkmultapWsfmadTUHLGEproDiglaaWRNAjjhFrdeomsScidfprgeXCplAceVmbsnisCONProapiOMGMWI2GomgmZdjBDgpompesfwqrAAFSDHV9OAmpFAlemYE5 * (int64_t) Cpx2;
    int64_t onsdaav46IT7GWUxSVONQU8anISBITmnsmUCMKKMnaMOntasmcONOSMMgtasmrtamqajomeTOPAAp63TEStbFaOXBvCon52raszKprkdkbibifaglDIodervCroobOCSw51odmarzFwqArsirkJordGoImetemlumasUnHOrragrSK5q8QnaptadbKinBuawinlasdczRizonrit2WRsvnUHUbsacJGNZOMaddWRHAbKmVGOGBnm4oqGuhtouchbortzUHUHLSLaWNPiWCplSRIMidsPrKlpJO4FInlrBastecyCHI = S * (int64_t) FWI;
    int64_t VBOMkbaknbombtxnxvBuabthaliONAYKKAjnshognATSCONcpMRla3rHOAvnWShnasdsMbi4lasgnEAIEaqtxbuhasmtEcUnaphPlekagoneaneusMEMJCtRamHJOmpquEplmdrassmar = sdf2o
