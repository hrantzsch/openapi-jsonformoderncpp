# build the generator and it's dependencies
# maven will also run the code in CppModernJsonGeneratorTest.java and
# generate DTOs for petstore.yaml in the 'out' folder
mvn clean install

# to invoke our generator directly, we need the openapi-generator CLI
if [ ! -f openapi-generator-cli.jar ]; then
    wget https://repo1.maven.org/maven2/org/openapitools/openapi-generator-cli/4.3.1/openapi-generator-cli-4.3.1.jar \
    -O openapi-generator-cli.jar
fi

command -v clang-format >/dev/null
if [ $? -eq 0 ]; then
    echo "found clang-format"
    export CPP_POST_PROCESS_FILE="$(which clang-format) -i -style=file -fallback-style=google"
    export FORMAT_FLAG="--enable-post-process-file"
fi

# run the generator for our yaml
java -cp ./openapi-generator-cli.jar:./target/cpp-modern-json-openapi-generator-1.0.0.jar \
-DskipFormModel=true \
org.openapitools.codegen.OpenAPIGenerator generate ${FORMAT_FLAG} \
-g cpp-modern-json \
--package-name=generated.dtos \
-i petstore.yaml -o ./generated
