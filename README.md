# Running the Code Generation

If maven is installed on your system, simply `./run.sh` should work.
It will install the dependencies for building the code generator, download a jar file for the openapi-generator-cli tool, and run the generator.

## In Docker

```bash
docker run --rm -i -t -v ${PWD}:/workspace -w /workspace maven:3-jdk-8 ./run.sh
```

# Code Formatting

The code generator can run a code formatter as a post processing step for each file.
This requires two things:

 * exporting the command you want to run as `CPP_POST_PROCESS_FILE`
 * calling the generator with `--enable-post-process-file`

See `run.sh` for an example.
