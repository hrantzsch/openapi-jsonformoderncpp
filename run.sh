# build the generator and it's dependencies
# maven will also run the code in CppModernJsonGeneratorTest.java and
# generate DTOs for petstore.yaml in the 'out' folder
mvn clean install

# to invoke our generator directly, we need the openapi-generator CLI
if [ ! -f openapi-generator-cli.jar ]; then
    wget https://repo1.maven.org/maven2/org/openapitools/openapi-generator-cli/4.2.3/openapi-generator-cli-4.2.3.jar \
    -O openapi-generator-cli.jar
fi

# run the generator for our yaml
java -cp ./openapi-generator-cli.jar:./target/cpp-modern-json-openapi-generator-1.0.0.jar \
org.openapitools.codegen.OpenAPIGenerator generate -g cpp-modern-json -i petstore.yaml -o ./generated
