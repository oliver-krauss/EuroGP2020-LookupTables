import sun.misc.DoubleConsts;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.time.Duration;
import java.time.Instant;
import java.util.*;
import java.util.stream.Collectors;

/**
 * @author Oliver Krauss on 19.08.2019
 */

public class Main {

  private static final String RECOMPILE_C = "csh build.bat";

  private static final String C_FOLDER = "../cbrt";

  private static final String RECOMPILE_C_NOLOG = "csh build.bat";

  private static final String C_NOLOG_FOLDER = "../cbrtNolog";

  private static final String RECOMPILE = "./build.bat";

  private static final String UF_FOLDER = "../userProvidedFn";

  private static final String UF_RUN_FOLDER = UF_FOLDER + "/cmake-build-debug/uF_";

  private static final double LOWER_BOUND = 0.5;

  private static final double UPPER_BOUND = 2.0;

  private static final double RANGE = UPPER_BOUND - LOWER_BOUND;

  private static final int TEST_POSITIONS = 512; // same as lookup tree size

  private static final int RANDOM_TEST_COUNT = 512; // to ensure with the fixed positions we get ~1000, and they have an equal amount

  private static final int SEED_CHECKING = 100; // to leave no doubt

  private static String getCmdForLanguage(Language language) {
    switch (language) {
      case C:
        return "../cbrt/main2 ";
      case CNoLog:
        return "../cbrtNolog/main2 ";
      case CSqrt:
        return UF_FOLDER + "/cmake-build-debug/sqrtC ";
      case CSurt:
        return UF_FOLDER + "/cmake-build-debug/surtC ";
      case CPPSqrt:
        return " ../cppComparison/cmake-build-debug/sqrtCpp ";
      case CPPCbrt:
        return " ../cppComparison/cmake-build-debug/cbrtCpp ";
      case CPPSurt:
        return " ../cppComparison/cmake-build-debug/surtCpp ";
      case JavaSqrt:
        return "java -jar ../javaComparison/target/sqrtJava.jar ";
      case JavaCbrt:
        return "java -jar ../javaComparison/target/cbrtJava.jar ";
      case JavaSurt:
        return "java -jar ../javaComparison/target/surtJava.jar ";
      case UFBitdiff:
        return UF_RUN_FOLDER + "Bitdiff ";
      case UFBitdiffVA:
        return UF_RUN_FOLDER + "BitdiffVA ";
      case UFHardLog:
        return UF_RUN_FOLDER + "HardLog ";
      case UFHardLogVA:
        return UF_RUN_FOLDER + "HardLogVA ";
      case UFLog:
        return UF_RUN_FOLDER + "Log ";
      case UFLogVA:
        return UF_RUN_FOLDER + "LogVA ";
      case UFMul:
        return UF_RUN_FOLDER + "Mul ";
      case UFMulVA:
        return UF_RUN_FOLDER + "MulVA ";
      case UFNoLog:
        return UF_RUN_FOLDER + "NoLog ";
      case UFNoLogVA:
        return UF_RUN_FOLDER + "NoLogVA ";
      case UFDistrBitdiff:
        return UF_RUN_FOLDER + "DistrBitdiff ";
      case UFDistrBitdiffVA:
        return UF_RUN_FOLDER + "DistrBitdiffVA ";
      case UFDistrHardLog:
        return UF_RUN_FOLDER + "DistrHardLog ";
      case UFDistrHardLogVA:
        return UF_RUN_FOLDER + "DistrHardLogVA ";
      case UFDistrLog:
        return UF_RUN_FOLDER + "DistrLog ";
      case UFDistrLogVA:
        return UF_RUN_FOLDER + "DistrLogVA ";
      case UFDistrMul:
        return UF_RUN_FOLDER + "DistrMul ";
      case UFDistrMulVA:
        return UF_RUN_FOLDER + "DistrMulVA ";
      case UFDistrNoLog:
        return UF_RUN_FOLDER + "DistrNoLog ";
      case UFDistrNoLogVA:
        return UF_RUN_FOLDER + "DistrNoLogVA ";
      case UFCenterBitdiff:
        return UF_RUN_FOLDER + "CenterBitdiff ";
      case UFCenterBitdiffVA:
        return UF_RUN_FOLDER + "CenterBitdiffVA ";
      case UFCenterBitdiffFN:
        return UF_RUN_FOLDER + "CenterBitdiffFN ";
      case UFCenterHardLog:
        return UF_RUN_FOLDER + "CenterHardLog ";
      case UFCenterHardLogVA:
        return UF_RUN_FOLDER + "CenterHardLogVA ";
      case UFCenterHardLogFN:
        return UF_RUN_FOLDER + "CenterHardLogFN ";
      case UFCenterLog:
        return UF_RUN_FOLDER + "CenterLog ";
      case UFCenterLogVA:
        return UF_RUN_FOLDER + "CenterLogVA ";
      case UFCenterLogFN:
        return UF_RUN_FOLDER + "CenterLogFN ";
      case UFCenterMul:
        return UF_RUN_FOLDER + "CenterMul ";
      case UFCenterMulVA:
        return UF_RUN_FOLDER + "CenterMulVA ";
      case UFCenterMulFN:
        return UF_RUN_FOLDER + "CenterMulFN ";
      case UFCenterNoLog:
        return UF_RUN_FOLDER + "CenterNoLog ";
      case UFCenterNoLogVA:
        return UF_RUN_FOLDER + "CenterNoLogVA ";
      case UFCenterNoLogFN:
        return UF_RUN_FOLDER + "CenterNoLogFN ";
      default:
        return null;
    }
  }

  private static Pair<String, String> getRecompileForLanguage(Language language) {
    switch (language) {
      case C:
        return new Pair<>(RECOMPILE_C, C_FOLDER);
      case CNoLog:
        return new Pair<>(RECOMPILE_C_NOLOG, C_NOLOG_FOLDER);
      case UFBitdiff:
        return new Pair<>(RECOMPILE + " Bitdiff", UF_FOLDER);
      case UFBitdiffVA:
        return new Pair<>(RECOMPILE + " BitdiffVA", UF_FOLDER);
      case UFHardLog:
        return new Pair<>(RECOMPILE + " HardLog", UF_FOLDER);
      case UFHardLogVA:
        return new Pair<>(RECOMPILE + " HardLogVA", UF_FOLDER);
      case UFLog:
        return new Pair<>(RECOMPILE + " Log", UF_FOLDER);
      case UFLogVA:
        return new Pair<>(RECOMPILE + " LogVA", UF_FOLDER);
      case UFMul:
        return new Pair<>(RECOMPILE + " Mul", UF_FOLDER);
      case UFMulVA:
        return new Pair<>(RECOMPILE + " MulVA", UF_FOLDER);
      case UFNoLog:
        return new Pair<>(RECOMPILE + " NoLog", UF_FOLDER);
      case UFNoLogVA:
        return new Pair<>(RECOMPILE + " NoLogVA", UF_FOLDER);
      case UFDistrBitdiff:
        return new Pair<>(RECOMPILE + " DistrBitdiff", UF_FOLDER);
      case UFDistrBitdiffVA:
        return new Pair<>(RECOMPILE + " DistrBitdiffVA", UF_FOLDER);
      case UFDistrHardLog:
        return new Pair<>(RECOMPILE + " DistrHardLog", UF_FOLDER);
      case UFDistrHardLogVA:
        return new Pair<>(RECOMPILE + " DistrHardLogVA", UF_FOLDER);
      case UFDistrLog:
        return new Pair<>(RECOMPILE + " DistrLog", UF_FOLDER);
      case UFDistrLogVA:
        return new Pair<>(RECOMPILE + " DistrLogVA", UF_FOLDER);
      case UFDistrMul:
        return new Pair<>(RECOMPILE + " DistrMul", UF_FOLDER);
      case UFDistrMulVA:
        return new Pair<>(RECOMPILE + " DistrMulVA", UF_FOLDER);
      case UFDistrNoLog:
        return new Pair<>(RECOMPILE + " DistrNoLog", UF_FOLDER);
      case UFDistrNoLogVA:
        return new Pair<>(RECOMPILE + " DistrNoLogVA", UF_FOLDER);
      case UFCenterBitdiff:
        return new Pair<>(RECOMPILE + " CenterBitdiff", UF_FOLDER);
      case UFCenterBitdiffVA:
        return new Pair<>(RECOMPILE + " CenterBitdiffVA", UF_FOLDER);
      case UFCenterBitdiffFN:
        return new Pair<>(RECOMPILE + " CenterBitdiffFN", UF_FOLDER);
      case UFCenterHardLog:
        return new Pair<>(RECOMPILE + " CenterHardLog", UF_FOLDER);
      case UFCenterHardLogVA:
        return new Pair<>(RECOMPILE + " CenterHardLogVA", UF_FOLDER);
      case UFCenterHardLogFN:
        return new Pair<>(RECOMPILE + " CenterHardLogFN", UF_FOLDER);
      case UFCenterLog:
        return new Pair<>(RECOMPILE + " CenterLog", UF_FOLDER);
      case UFCenterLogVA:
        return new Pair<>(RECOMPILE + " CenterLogVA", UF_FOLDER);
      case UFCenterLogFN:
        return new Pair<>(RECOMPILE + " CenterLogFN", UF_FOLDER);
      case UFCenterMul:
        return new Pair<>(RECOMPILE + " CenterMul", UF_FOLDER);
      case UFCenterMulVA:
        return new Pair<>(RECOMPILE + " CenterMulVA", UF_FOLDER);
      case UFCenterMulFN:
        return new Pair<>(RECOMPILE + " CenterMulFN", UF_FOLDER);
      case UFCenterNoLog:
        return new Pair<>(RECOMPILE + " CenterNoLog", UF_FOLDER);
      case UFCenterNoLogVA:
        return new Pair<>(RECOMPILE + " CenterNoLogVA", UF_FOLDER);
      case UFCenterNoLogFN:
        return new Pair<>(RECOMPILE + " CenterNoLogFN", UF_FOLDER);
      default:
        return null; // for example we never need to recompile the C, C++ or Java references
    }
  }

  private static String humanReadable(Language language) {
    switch (language) {
      case C:
        return "C                      ";
      case CNoLog:
        return "C NoLog                ";
      case CSqrt:
        return "C Sqrt                 ";
      case CSurt:
        return "C Surt                 ";
      case CPPSqrt:
        return "C++ Sqrt               ";
      case CPPCbrt:
        return "C++ Cbrt               ";
      case CPPSurt:
        return "C++ Surt               ";
      case JavaSqrt:
        return "Java Sqrt              ";
      case JavaCbrt:
        return "Java Cbrt              ";
      case JavaSurt:
        return "Java Surt              ";
      case UFBitdiff:
        return "UF Bitdiff Cbrt        ";
      case UFBitdiffVA:
        return "UF BitdiffVA Cbrt      ";
      case UFHardLog:
        return "UF HardLog Cbrt        ";
      case UFHardLogVA:
        return "UF HardLogVA Cbrt      ";
      case UFLog:
        return "UF Log Cbrt            ";
      case UFLogVA:
        return "UF LogVA Cbrt          ";
      case UFMul:
        return "UF Mul Cbrt            ";
      case UFMulVA:
        return "UF MulVA Cbrt          ";
      case UFNoLog:
        return "UF NoLog Cbrt          ";
      case UFNoLogVA:
        return "UF NoLogVA Cbrt        ";
      case UFDistrBitdiff:
        return "UFDistr Bitdiff Cbrt   ";
      case UFDistrBitdiffVA:
        return "UFDistr BitdiffVA Cbrt ";
      case UFDistrHardLog:
        return "UFDistr HardLog Cbrt   ";
      case UFDistrHardLogVA:
        return "UFDistr HardLogVA Cbrt ";
      case UFDistrLog:
        return "UFDistr Log Cbrt       ";
      case UFDistrLogVA:
        return "UFDistr LogVA Cbrt     ";
      case UFDistrMul:
        return "UFDistr Mul Cbrt       ";
      case UFDistrMulVA:
        return "UFDistr MulVA Cbrt     ";
      case UFDistrNoLog:
        return "UFDistr NoLog Cbrt     ";
      case UFDistrNoLogVA:
        return "UFDistr NoLogVA Cbrt   ";
      case UFCenterBitdiff:
        return "UFCenter Bitdiff Cbrt  ";
      case UFCenterBitdiffVA:
        return "UFCenter BitdiffVA Cbrt";
      case UFCenterBitdiffFN:
        return "UFCenter BitdiffFN Cbrt";
      case UFCenterHardLog:
        return "UFCenter HardLog Cbrt  ";
      case UFCenterHardLogVA:
        return "UFCenter HardLogVA Cbrt";
      case UFCenterHardLogFN:
        return "UFCenter HardLogFN Cbrt";
      case UFCenterLog:
        return "UFCenter Log Cbrt      ";
      case UFCenterLogVA:
        return "UFCenter LogVA Cbrt    ";
      case UFCenterLogFN:
        return "UFCenter LogFN Cbrt    ";
      case UFCenterMul:
        return "UFCenter Mul Cbrt      ";
      case UFCenterMulVA:
        return "UFCenter MulVA Cbrt    ";
      case UFCenterMulFN:
        return "UFCenter MulFN Cbrt    ";
      case UFCenterNoLog:
        return "UFCenter NoLog Cbrt    ";
      case UFCenterNoLogVA:
        return "UFCenter NoLogVA Cbrt  ";
      case UFCenterNoLogFN:
        return "UFCenter NoLogFN Cbrt  ";
      default:
        return null;
    }
  }

  /**
   * @param LOWER_BOUND
   * @param UPPER_BOUND
   * @param comparisonLanguages
   * @param referenceLanguages
   * @throws Exception
   */
  public static void doComparison(double LOWER_BOUND, double UPPER_BOUND, List<Language> comparisonLanguages, List<Language> referenceLanguages) throws Exception {
    Random r = new Random();

    // check between given bounds instead of the regular range
    double RANGE = UPPER_BOUND - LOWER_BOUND;
    double increment = RANGE / TEST_POSITIONS;
    double[] fixedValues = new double[TEST_POSITIONS];
    for (int i = 0; i < TEST_POSITIONS; i++) {
      fixedValues[i] = LOWER_BOUND + increment * i;
    }

    Map<Language, Integer> csvAccessor = new HashMap<>();
    int cl = 0;
    for (Language comparisonLanguage : comparisonLanguages) {
      csvAccessor.put(comparisonLanguage, cl);
      cl++;
    }
    double[][] evenCSV = new double[comparisonLanguages.size()][SEED_CHECKING];
    double[][] randomCSV = new double[comparisonLanguages.size()][SEED_CHECKING];
    double[][] compiletimeCSV = new double[comparisonLanguages.size()][SEED_CHECKING];
    long[][] evenPerfectCSV = new long[comparisonLanguages.size()][SEED_CHECKING];
    long[][] randomPerfectCSV = new long[comparisonLanguages.size()][SEED_CHECKING];

    // randomize but ensure that ALL seeds test on the same values so we can check if the seed makes a difference
    double[] randomValues = new double[RANDOM_TEST_COUNT];
    for (int i = 0; i < randomValues.length; i++) {
      randomValues[i] = LOWER_BOUND + RANGE * r.nextDouble();
    }

    // prepare comparison with seed of 140353 (the original from Langdon and Petke)
    Vector<ExecResult> comparisonResults = new Vector<>();
    Vector<ExecResult> comparisonResultsRandom = new Vector<>();
//    for (Language language : comparisonLanguages) {
//      Pair<String, String> recompileCommand = getRecompileForLanguage(language);
//      if (recompileCommand != null) {
//        recompile(recompileCommand.getKey(), recompileCommand.getValue(), "140353");
//      }
//    }
    addExec(fixedValues, comparisonResults, referenceLanguages);
    addExec(randomValues, comparisonResultsRandom, referenceLanguages);
    printResults("Comparison FIXED", comparisonResults);
    printResults("Comparison RANDOM", comparisonResultsRandom);
    System.out.println("---------");

    // calculate the reference errors
    Map<Language, Double> referenceError = new HashMap<>();
    Map<Language, Double> referenceErrorRnd = new HashMap<>();
    referenceLanguages.forEach(x -> {
      referenceError.put(x, getError(x, comparisonResults));
      referenceErrorRnd.put(x, getError(x, comparisonResultsRandom));
    });

    // Set up count of which is better (may not necessarily be 1000 if they are exactly the same)
    Map<Language, Map<Language, Integer>> better = new HashMap<>();
    Map<Language, Map<Language, Integer>> betterRnd = new HashMap<>();
    comparisonLanguages.forEach(x -> {
      better.put(x, new HashMap<>());
      betterRnd.put(x, new HashMap<>());
      comparisonLanguages.stream().filter(y -> y != x).forEach(y -> {
        better.get(x).put(y, 0);
        betterRnd.get(x).put(y, 0);
      });
      referenceLanguages.stream().forEach(y -> {
        better.get(x).put(y, 0);
        betterRnd.get(x).put(y, 0);
      });
    });

    for (int i = 0; i < SEED_CHECKING; i++) {
      int finalI = i;
      // clean the files that for some reason CMAES doesn't want to clean
      new File(UF_FOLDER + "/cmake-build-debug/errcmaes.err").delete();
      new File(UF_FOLDER + "/cmake-build-debug/allcmaes.dat").delete();
      new File(UF_FOLDER + "/cmake-build-debug/actparcmaes.par").delete();

      // recompile C and C Nolog with same seed (prevent seed from becoming 0)
      String seed = String.valueOf(r.nextInt(1000000 - 1) + 1);
      System.out.print("Attempt " + i + " seed " + seed + " ");
      comparisonLanguages.parallelStream().forEach(x -> {
        Pair<String, String> rCommand = getRecompileForLanguage(x);
        Instant start = Instant.now();
        try {
          recompile(rCommand.getKey(), rCommand.getValue(), seed);
        } catch (Exception e) {
          e.printStackTrace();
        }
        Instant finish = Instant.now();
        double timeElapsed = Duration.between(start, finish).toMillis();
        compiletimeCSV[csvAccessor.get(x)][finalI] = timeElapsed;
        System.out.print(". " + humanReadable(x).trim() + " (" + timeElapsed + ") ");
      });
      System.out.println();


      // run evenly distributed range checks
      List<ExecResult> evenlyDistributedResults = new Vector<>();
      Arrays.stream(fixedValues).parallel().forEach(x -> {
        try {
          for (Language cmd : comparisonLanguages) {
            evenlyDistributedResults.add(run(cmd, x));

          }
        } catch (Exception e) {
          e.printStackTrace();
        }
      });
      printResults("Even Distribution", evenlyDistributedResults);

      // run randomly distributed values
      List<ExecResult> randomTestPositionResults = new Vector<>();
      Arrays.stream(randomValues).parallel().forEach(x -> {
        try {
          for (Language cmd : comparisonLanguages) {
            randomTestPositionResults.add(run(cmd, x));
          }
        } catch (Exception e) {
          e.printStackTrace();
        }
      });
      printResults("Random Distribution", randomTestPositionResults);

      // do the comparison that we are interested in
      Map<Language, Double> error = new HashMap<>();
      Map<Language, Double> errorRnd = new HashMap<>();
      comparisonLanguages.forEach(x -> {
        double err = getError(x, evenlyDistributedResults);
        double errRnd = getError(x, randomTestPositionResults);
        error.put(x, err);
        errorRnd.put(x, errRnd);
        evenCSV[csvAccessor.get(x)][finalI] = err;
        evenPerfectCSV[csvAccessor.get(x)][finalI] = getAmountPerfect(x, evenlyDistributedResults);
        randomCSV[csvAccessor.get(x)][finalI] = errRnd;
        randomPerfectCSV[csvAccessor.get(x)][finalI] = getAmountPerfect(x, randomTestPositionResults);
      });

      comparisonLanguages.forEach(x -> {
        double selfError = error.get(x);
        double selfErrorRnd = errorRnd.get(x);
        // compare the languages amongst each other
        error.entrySet().stream().filter(entry -> entry.getKey() != x && entry.getValue() > selfError).forEach(entry -> {
          better.get(x).put(entry.getKey(), better.get(x).get(entry.getKey()) + 1);
        });
        errorRnd.entrySet().stream().filter(entry -> entry.getKey() != x && entry.getValue() > selfErrorRnd).forEach(entry -> {
          betterRnd.get(x).put(entry.getKey(), betterRnd.get(x).get(entry.getKey()) + 1);
        });
        // compare the languages to the refs
        referenceError.entrySet().stream().filter(entry -> entry.getValue() > selfError).forEach(entry -> {
          better.get(x).put(entry.getKey(), better.get(x).get(entry.getKey()) + 1);
        });
        referenceErrorRnd.entrySet().stream().filter(entry -> entry.getValue() > selfErrorRnd).forEach(entry -> {
          betterRnd.get(x).put(entry.getKey(), betterRnd.get(x).get(entry.getKey()) + 1);
        });
      });
    }

    // show us the final results:
    comparisonLanguages.forEach(x -> {
      System.out.println("---------");
      System.out.println(humanReadable(x) + " in evenly spaced distribution is better than");
      better.get(x).entrySet().forEach(y -> {
        System.out.println("  " + humanReadable(y.getKey()) + " in " + y.getValue() + " of " + SEED_CHECKING + " cases");
      });
      System.out.println(humanReadable(x) + " in randomly spaced distribution is better than");
      betterRnd.get(x).entrySet().forEach(y -> {
        System.out.println("  " + humanReadable(y.getKey()) + " in " + y.getValue() + " of " + SEED_CHECKING + " cases");
      });
    });

    // Drumroll
    System.out.println("---------");
    System.out.println("The different implementations have NO impact in " +
        (SEED_CHECKING -
            better.entrySet().stream().flatMap(x -> x.getValue().entrySet().stream().filter(y -> y.getKey() != x.getKey() && comparisonLanguages.contains(y.getKey()))).mapToInt(y -> y.getValue()).sum())
        + " / " + SEED_CHECKING + " evenly distributed cases");
    System.out.println("The different implementations have NO impact in " +
        (SEED_CHECKING -
            betterRnd.entrySet().stream().flatMap(x -> x.getValue().entrySet().stream().filter(y -> y.getKey() != x.getKey() && comparisonLanguages.contains(y.getKey()))).mapToInt(y -> y.getValue()).sum())
        + " / " + SEED_CHECKING + " random cases");

    System.out.println("---------");


    //  print CSV to calculate mean, median, normal distribution and statistical test externally
    String header = csvAccessor.entrySet().stream().sorted(Comparator.comparingInt(Map.Entry::getValue)).map(x -> humanReadable(x.getKey()).trim()).collect(Collectors.joining(","));
    System.out.println("EVEN CSV");
    System.out.println(header);
    printCSV(evenCSV);
    System.out.println("RND CSV");
    System.out.println(header);
    printCSV(randomCSV);
    System.out.println("TIMINGS");
    System.out.println(header);
    printCSV(compiletimeCSV);
    System.out.println("Exact Hits EVEN CSV");
    System.out.println(header);
    printCSV(evenPerfectCSV);
    System.out.println("Exact Hits RANDOM CSV");
    System.out.println(header);
    printCSV(randomPerfectCSV);
  }

  protected static void printCSV(double[][] evenCSV) {
    for (int line = 0; line < SEED_CHECKING; line++) {
      String str = "";
      for (int col = 0; col < evenCSV.length; col++) {
        str = str + evenCSV[col][line] + ",";
      }
      str = str.substring(0, str.length() - 1);
      System.out.println(str);
    }
  }

  protected static void printCSV(long[][] evenCSV) {
    for (int line = 0; line < SEED_CHECKING; line++) {
      String str = "";
      for (int col = 0; col < evenCSV.length; col++) {
        str = str + evenCSV[col][line] + ",";
      }
      str = str.substring(0, str.length() - 1);
      System.out.println(str);
    }
  }

  protected static void addExec(double[] fixedValues, List<ExecResult> resultList, List<Language> commands) {
    Arrays.stream(fixedValues).parallel().forEach(x -> {
      try {
        commands.forEach(cmd -> {
          try {
            resultList.add(run(cmd, x));
          } catch (Exception e) {
            e.printStackTrace();
          }
        });
      } catch (Exception e) {
        e.printStackTrace();
      }
    });
  }

  public static void main(String[] args) throws Exception {
    // Warning: you need to COMPILE all reference projects before this works once!

    // Do the checking fromb 2.2 if Log or Seed have an impact
    List<Language> logComparison = Arrays.asList(Language.C, Language.CNoLog);
    List<Language> logReferenceComparison = Arrays.asList(Language.C, Language.CPPCbrt, Language.JavaCbrt);
    //doComparison(0.5, 10000, logComparison, logReferenceComparison);

    // Do check if the same holds true for our user function
    List<Language> ufComparison = Arrays.asList(Language.UFBitdiff, Language.UFBitdiffVA, Language.UFHardLog, Language.UFHardLogVA, Language.UFLog, Language.UFLogVA, Language.UFMul, Language.UFMulVA, Language.UFNoLog, Language.UFNoLogVA,
        Language.UFDistrBitdiff, Language.UFDistrBitdiffVA, Language.UFDistrHardLog, Language.UFDistrHardLogVA, Language.UFDistrLog, Language.UFDistrLogVA, Language.UFDistrMul, Language.UFDistrMulVA, Language.UFDistrNoLog, Language.UFDistrNoLogVA,
        Language.UFCenterBitdiff, Language.UFCenterBitdiffVA, Language.UFCenterBitdiffFN, Language.UFCenterHardLog, Language.UFCenterHardLogVA, Language.UFCenterHardLogFN, Language.UFCenterLog, Language.UFCenterLogVA, Language.UFCenterLogFN, Language.UFCenterMul, Language.UFCenterMulVA, Language.UFCenterMulFN, Language.UFCenterNoLog, Language.UFCenterNoLogVA, Language.UFCenterNoLogFN
    );

    // TO compare different functions you need to set the ufReference comparison to the correct comparators AND
    // in the userProvidedFn project set CmakeLists.txt:17 to the correct user function
    List<Language> ufReferenceComparison = Arrays.asList(Language.CSurt, Language.CPPSurt, Language.JavaSurt); //Language.CSurt, Language.CPPSurt, Language.JavaSurt
    doComparison(0.5, 2.0, ufComparison, ufReferenceComparison);


    if (true) {
      return;
    }
    // Note: The benchmarks are currently MANUAL, please run the respective Benchmarking functions in the reference projects

  // Note: these tests are not relevant unless you want to test how your function behaves in extreme values or edge cases
//
//    // Evaluate Extreme Values
//    evaluate(allResults, 1.7976931348623157E308;
//    evaluate(allResults, -1.7976931348623157E308);
//    evaluate(allResults, -1.7976931348623158E308);
//    evaluate(allResults, 1.7976931348623158E308);
//
//    //Evaluate really small numbers
//    evaluate(allResults, Math.nextUp(0F));
//    evaluate(allResults, Math.nextUp(0D));
//    evaluate(allResults, Math.nextDown(0F));
//    evaluate(allResults, Math.nextDown(0D));
////
//    evaluate(allResults, Math.nextUp(1F));
//    evaluate(allResults, Math.nextUp(1D));
//    evaluate(allResults, Math.nextDown(1F));
//    evaluate(allResults, Math.nextDown(1D));

//    for (int i = 300; i < 320; i++) {
//      evaluate(allResults, Double.valueOf("-1.0E-" + i));
//    }
    // evaluate(allResults, Double.NaN);
    // evaluate(allResults, Float.NaN);
  }

  private static void printResults(String name, List<ExecResult> results) {
    System.out.println(name);
    for (Language value : Language.values()) {
      if (results.stream().anyMatch(x -> x.language == value)) {
        System.out.println(humanReadable(value) + " ERR " + getError(value, results) + " CNT " + getAmountPerfect(value, results));
      }
    }
  }

  private static double getError(Language language, List<ExecResult> results) {
    return results.stream().filter(x -> x.language == language).mapToDouble(o -> Math.abs(Double.valueOf(o.reversed) - Double.valueOf(o.value))).sum();
  }

  private static long getAmountPerfect(Language language, List<ExecResult> results) {
    return results.stream().filter(x -> x.language == language && x.perfect).count();
  }

  private static String toStringNan(Double d) {
    StringBuilder answer = new StringBuilder(24);

    if (Math.copySign(1.0, d) == -1.0)    // value is negative,
      answer.append("-");                  // so append sign info

    answer.append("0x");

    d = Math.abs(d);

    if (d == 0.0) {
      answer.append("0.0p0");
    } else {
      boolean subnormal = (d < DoubleConsts.MIN_NORMAL);

      // Isolate significand bits and OR in a high-order bit
      // so that the string representation has a known
      // length.
      long signifBits = (Double.doubleToLongBits(d)
          & DoubleConsts.SIGNIF_BIT_MASK) |
          0x1000000000000000L;

      // Subnormal values have a 0 implicit bit; normal
      // values have a 1 implicit bit.
      answer.append(subnormal ? "0." : "1.");

      // Isolate the low-order 13 digits of the hex
      // representation.  If all the digits are zero,
      // replace with a single 0; otherwise, remove all
      // trailing zeros.
      String signif = Long.toHexString(signifBits).substring(3, 16);
      answer.append(signif.equals("0000000000000") ? // 13 zeros
          "0" :
          signif.replaceFirst("0{1,12}$", ""));

      answer.append('p');
      // If the value is subnormal, use the E_min exponent
      // value for double; otherwise, extract and report d's
      // exponent (the representation of a subnormal uses
      // E_min -1).
      answer.append(subnormal ?
          DoubleConsts.MIN_EXPONENT :
          Math.getExponent(d));
    }
    return answer.toString();
  }

  private static void evaluate(List<ExecResult> allResults, double value) throws Exception {
    List<ExecResult> results = new LinkedList<>();
    results.add(run(Language.C, value));
    results.add(run(Language.CNoLog, value));
    results.add(run(Language.CPPCbrt, value));
    results.add(run(Language.JavaCbrt, value));
//    results.add(run(CMD_UF, value));
    allResults.addAll(results);

//    String s = String.valueOf(value);
//    ExecResult best = null;
//    if (results.stream().anyMatch(o -> o.value.compareTo(o.reversed) == 0)) {
//      best = results.stream().filter(o -> o.value.compareTo(o.reversed) == 0).findFirst().get();
//    } else if (results.stream().allMatch(x -> Math.abs(Double.valueOf(x.reversed) - value) == 0)) {
//      // fallback to string compare
//      best = results.stream().sorted(Comparator.comparingInt(o -> {
//        int j = 0, i = 0;
//        String oS = String.valueOf(o.reversed);
//        while (s.length() > i) {
//          if (oS.length() > i && s.charAt(i) == oS.charAt(i)) {
//            j = i;
//          } else {
//            return j;
//          }
//          i++;
//        }
//        return j * -1;
//      })).findFirst().get();
//    } else {
//      best = results.stream().sorted(Comparator.comparingDouble(o -> Math.abs((o.reversed.contains("NaN") || o.reversed.contains("nan") || o.reversed.contains("inf") ? 10000 : Double.valueOf(o.reversed)) - value))).findFirst().get();
//    }
  }

  private static void recompile(String cmd, String folder, String value) throws Exception {
    Runtime rt = Runtime.getRuntime();
    // sometimes the recompile fails due to executing it in parallel (file locks during build) lets do repeats to prevent this

    boolean success = false;
    int repeats = 5;
    while (success == false && repeats > 0) {
      try {
        Process pr = rt.exec(cmd + " " + value, null, new File(folder));
        pr.waitFor();
        if (pr.exitValue() == 0) {
          success = true;
        } else {
          repeats--;
          if (repeats <= 0) {
            BufferedReader reader =
                new BufferedReader(new InputStreamReader(pr.getInputStream()));
            String line = null;
            while ((line = reader.readLine()) != null) {
              System.out.println(line);
            }
          }
        }
      } catch (IOException e) {
      } catch (InterruptedException e) {
      }
    }
  }

  private static ExecResult run(Language language, double value) throws Exception {
    String cmd = getCmdForLanguage(language);

    ExecResult result = new ExecResult();
    result.value = String.valueOf(value);

    Runtime rt = Runtime.getRuntime();
    Process pr = rt.exec(cmd + value);
    pr.waitFor();

    BufferedReader reader =
        new BufferedReader(new InputStreamReader(pr.getInputStream()));
    ;
    String line = null;
    while ((line = reader.readLine()) != null) {
      if (line.startsWith("Reversed")) {
        result.reversed = line.substring(line.indexOf("Reversed") + "Reversed ".length());
      }
      if (line.contains("Bprc")) {
        result.newtonApproximation = line.substring(line.indexOf("Bprc") + "Bprc ".length());
        result.newtonApproximation = result.newtonApproximation.substring(0, result.newtonApproximation.indexOf(" "));
        result.newtonApproximationInHex = line.substring(line.indexOf("Bhex") + "Bhex ".length());
        result.language = language;
      }
      if (line.contains("Perfect Result")) {
        result.perfect = true;
      }
    }

    return result;
  }
}
