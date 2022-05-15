# wBugFix

i recently added these 3 lines of code to unnoficial-zimbu/lib/STRINGModule.zu


    dyn wBugFix = 0
    IF wBugFix == 0
    }


## but, why?

first of all, the 'w' in wBugFix stands for weird.

it all started with a test, i was trying to use the string $format function 
and i was getting this weird error message

    $ zup --run
    bla bla bla, check buildlog
  
    $ cat buildlog
    ...
    Warning: implicit definition of ZdynEqual
    ...
    ld: undefined reference to ZdynEqual
    ...

and then i started to investigate, i opened target/c/main.c (same as ZUDIR/*.c)
and in the c file i found something interesting, ZdynEqual wasn't there 
(i know this is exactly what the compiler said).

## if ZdynEqual doesn't exist, why we can compare two dyn's normally?

that was exactly what i thought, and then, in a separate file, i started testing stuff

    $ zup --new test
    $ cd test && vim src/main.zu && zup --run

the contents of the file were exactly

    FUNC Main() int
      dyn a = 0
      IF a == 0
      }
    }

and, unsurprisingly, it worked, but i wanted even more, i started looking at the c file
and what i found?
    
    int ZdynEqual(Tx a, Tx b) {
      return ZitemEqual(a.type, a.u, b.type, b.u);
    }

exactly! ZdynEqual, it turns out that for some weird reason, the code generator
forgot to put the function in, and then i just tried putting this thing in the source code for
$format, and it worked like a charm.
