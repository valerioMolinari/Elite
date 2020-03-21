public class Interfaces  {
    interface ZeroLoop {
        void exec(int iLimit, int jLimit, Operation op);
    }

    interface Loop {
        void exec(int i, int j, int iLimit, int jLimit, Operation op);
    }

    interface Operation {
        void exec(int i, int j);
    }

    Loop loop = (it1, it2, iLimit, jLimit, op) -> {
        for (int i = it1; i < iLimit; i++)
            for (int j = it2; j < jLimit; j++)
                op.exec(i, j);
    };

    ZeroLoop zeroLoop = (iLimit, jLimit, op) -> loop.exec(0, 0, iLimit, jLimit, op);
}