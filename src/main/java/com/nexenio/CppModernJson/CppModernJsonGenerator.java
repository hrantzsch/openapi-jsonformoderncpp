package com.nexenio.CppModernJson;

import io.swagger.v3.oas.models.media.ArraySchema;
import io.swagger.v3.oas.models.media.Schema;
import java.io.File;
import java.util.*;
import org.apache.commons.lang3.StringUtils;
import org.openapitools.codegen.*;
import org.openapitools.codegen.languages.AbstractCppCodegen;
import org.openapitools.codegen.utils.ModelUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class CppModernJsonGenerator extends AbstractCppCodegen implements CodegenConfig {
  private static final Logger LOGGER = LoggerFactory.getLogger(CppModernJsonGenerator.class);

  protected String projectName = "cpp-modern-json";

  /** Version of the nlohmann/json library to use. Used in the CMakeLists and conanfile. */
  protected String nlohmannJsonVersion = "3.7.3";

  // source folder where to write the files
  protected String modelsFolderName = "models";

  protected String apiVersion = "14";
  protected String packageName = "org.openapitools";

  protected String packageToPath(String packageName) {
    return packageName.replace('.', File.separatorChar);
  }

  /**
   * Configures the type of generator.
   *
   * @return the CodegenType for this generator
   * @see org.openapitools.codegen.CodegenType
   */
  public CodegenType getTag() {
    return CodegenType.SCHEMA;
  }

  /**
   * Configures a friendly name for the generator. This will be used by the generator to select the
   * library with the -g flag.
   *
   * @return the friendly name for the generator
   */
  public String getName() {
    return projectName;
  }

  /** Provides an opportunity to inspect and modify operation data before the code is generated. */
  @SuppressWarnings("unchecked")
  @Override
  public Map<String, Object> postProcessOperationsWithModels(
      Map<String, Object> objs, List<Object> allModels) {
    // to try debugging your code generator:
    // set a break point on the next line.
    // then debug the JUnit test called LaunchGeneratorInDebugger

    Map<String, Object> results = super.postProcessOperationsWithModels(objs, allModels);

    Map<String, Object> ops = (Map<String, Object>) results.get("operations");
    ArrayList<CodegenOperation> opList = (ArrayList<CodegenOperation>) ops.get("operation");

    // iterate over the operation and perhaps modify something
    for (CodegenOperation co : opList) {
      // example:
      // co.httpMethod = co.httpMethod.toLowerCase();
    }

    return results;
  }

  /**
   * Returns human-friendly help for the generator. Provide the consumer with help tips, parameters
   * here
   *
   * @return A string value for the help message
   */
  public String getHelp() {
    return "Generates a cpp-modern-json client library.";
  }

  public CppModernJsonGenerator() {
    super();

    /** Output folder. */
    outputFolder = "generated-code/cpp-modern-json";

    /** Models. */
    modelTemplateFiles.put("model-header.mustache", ".h");
    modelTemplateFiles.put("model-source.mustache", ".cpp");

    /** Template Location. This is the location which templates will be read from. */
    templateDir = "cpp-modern-json";

    /**
     * Language Specific Primitives. These types will not trigger imports by the client generator
     */
    languageSpecificPrimitives =
        new HashSet<String>(
            Arrays.asList("int", "char", "bool", "long", "float", "double", "int32_t", "int64_t"));

    /** Type Mappings. From openAPI types to C++ types */
    typeMapping = new HashMap<String, String>();

    typeMapping.put("ByteArray", "std::string");
    typeMapping.put("date", "std::string");
    typeMapping.put("DateTime", "std::string");
    typeMapping.put("file", "std::string");
    typeMapping.put("URI", "std::string");
    typeMapping.put("UUID", "std::string");

    typeMapping.put("array", "std::vector");
    typeMapping.put("binary", "std::string");
    typeMapping.put("map", "std::map");
    typeMapping.put("string", "std::string");

    typeMapping.put("boolean", "bool");
    typeMapping.put("integer", "int32_t");
    typeMapping.put("long", "int64_t");
    typeMapping.put("number", "double");

    // raw, nested json objects
    typeMapping.put("object", "::nlohmann::json");

    /** Import Mappings. Include statements for std types */
    super.importMapping = new HashMap<String, String>();
    importMapping.put("std::vector", "#include <vector>");
    importMapping.put("std::map", "#include <map>");
    importMapping.put("std::string", "#include <string>");

    // Models containing an 'object' will attempt to import "::nlohmann::json" (see type-mapping
    // above). Don't.
    importMapping.put("::nlohmann::json", "");

    addOption(CodegenConstants.PROJECT_NAME, "project name", projectName);
  }

  @Override
  public void processOpts() {
    super.processOpts();

    // {{nlohmannJsonVersion}}
    //
    additionalProperties.put("nlohmannJsonVersion", nlohmannJsonVersion);

    // {{apiVersion}}
    //
    additionalProperties.put("apiVersion", apiVersion);

    // {{projectName}}
    //
    if (additionalProperties.containsKey(CodegenConstants.PROJECT_NAME)) {
      projectName = (String) additionalProperties.get(CodegenConstants.PROJECT_NAME);
    } else {
      additionalProperties.put(CodegenConstants.PROJECT_NAME, projectName);
    }

    // {{packageName}}
    //
    if (additionalProperties.containsKey(CodegenConstants.PACKAGE_NAME)) {
      packageName = (String) additionalProperties.get(CodegenConstants.PACKAGE_NAME);
    } else {
      additionalProperties.put(CodegenConstants.PACKAGE_NAME, packageName);
    }

    // {{modelPackage}}, {{modelNamespace}}, {{modelNamespaceDeclarations}},
    // {{modelHeaderGuardPrefix}}
    //
    // {{modelPackage}} defaults to {{packageName}}.models (others accordingly)
    // override using `--model-package`
    //
    if (additionalProperties.containsKey(CodegenConstants.MODEL_PACKAGE)) {
      modelPackage = (String) additionalProperties.get(CodegenConstants.MODEL_PACKAGE);
    } else {
      modelPackage = packageName + "." + modelsFolderName;
      additionalProperties.put(CodegenConstants.MODEL_PACKAGE, modelPackage);
    }
    additionalProperties.put("modelNamespace", modelPackage.replaceAll("\\.", "::"));
    additionalProperties.put("modelNamespaceDeclarations", modelPackage.split("\\."));
    additionalProperties.put(
        "modelHeaderGuardPrefix", modelPackage.replaceAll("\\.", "_").toUpperCase(Locale.ROOT));

    // {{scmUrl}}
    //
    // mandatory in order to use the conanfile
    //
    if (!additionalProperties.containsKey(CodegenConstants.SCM_URL)) {
      LOGGER.warn(
          "SCM URL is not set. conanfile will be broken. Please pass '-p scmUrl=https://...' to the generator.");
    }

    /**
     * Supporting Files. You can write single files for the generator with the entire object tree
     * available. If the input file has a suffix of `.mustache it will be processed by the template
     * engine. Otherwise, it will be copied
     */
    // (<file>, <destination folder relative to `outputFolder`>, <target filename>)

    String packagePath = packageToPath(packageName);
    additionalProperties.put("packagePath", packagePath);

    String modelPath = packageToPath(modelPackage);
    additionalProperties.put("modelPath", modelPath);

    supportingFiles.add(
        new SupportingFile("serialization.mustache", packagePath, "serialization.h"));
    supportingFiles.add(new SupportingFile("utility.mustache", packagePath, "utility.h"));

    supportingFiles.add(new SupportingFile("CMakeLists.mustache", "", "CMakeLists.txt"));
    supportingFiles.add(new SupportingFile("conanfile.mustache", "", "conanfile.py"));
  }

  /** Convert model name to file name. */
  @Override
  public String toModelFilename(String name) {
    return toModelName(name);
  }

  @Override
  public String getSchemaType(Schema p) {
    String openAPIType = super.getSchemaType(p);
    String type = null;
    if (typeMapping.containsKey(openAPIType)) {
      type = typeMapping.get(openAPIType);
      if (languageSpecificPrimitives.contains(type)) return toModelName(type);
    } else type = openAPIType;
    return toModelName(type);
  }

  @Override
  public String toModelImport(String name) {
    if (importMapping.containsKey(name)) {
      return importMapping.get(name);
    } else {
      return "#include \"" + name + ".h\"";
    }
  }

  @Override
  public CodegenModel fromModel(String name, Schema model) {
    CodegenModel codegenModel = super.fromModel(name, model);

    Set<String> oldImports = codegenModel.imports;
    codegenModel.imports = new HashSet<>();
    for (String imp : oldImports) {
      String newImp = toModelImport(imp);
      if (!newImp.isEmpty()) {
        codegenModel.imports.add(newImp);
      }
    }

    return codegenModel;
  }

  /**
   * Enum name for a property. This is used to set datatypeWithEnum
   *
   * @return the capitalized `name` of the property
   */
  @Override
  public String toEnumName(CodegenProperty property) {
    return StringUtils.capitalize(property.name);
  }

  /**
   * Optional - type declaration. This is a String which is used by the templates to instantiate
   * your types. There is typically special handling for different property types
   *
   * @return a string value used as the `dataType` field for model templates, `returnType` for api
   *     templates
   */
  @Override
  public String getTypeDeclaration(Schema p) {
    String openAPIType = getSchemaType(p);

    if (ModelUtils.isArraySchema(p)) {
      ArraySchema ap = (ArraySchema) p;
      Schema inner = ap.getItems();
      return getSchemaType(p) + "<" + getTypeDeclaration(inner) + ">";
    }
    if (ModelUtils.isMapSchema(p)) {
      Schema inner = ModelUtils.getAdditionalProperties(p);
      return getSchemaType(p) + "<std::string, " + getTypeDeclaration(inner) + ">";
    } else if (ModelUtils.isByteArraySchema(p)) {
      return "std::string";
    }
    if (ModelUtils.isStringSchema(p)
        || ModelUtils.isDateSchema(p)
        || ModelUtils.isDateTimeSchema(p)
        || ModelUtils.isFileSchema(p)
        || languageSpecificPrimitives.contains(openAPIType)) {
      return toModelName(openAPIType);
    }

    return openAPIType;
  }

  /**
   * override with any special text escaping logic to handle unsafe characters so as to avoid code
   * injection
   *
   * @param input String to be cleaned up
   * @return string with unsafe characters removed or escaped
   */
  @Override
  public String escapeUnsafeCharacters(String input) {
    // TODO: check that this logic is safe to escape unsafe characters to avoid code injection
    return input;
  }

  /**
   * Escape single and/or double quote to avoid code injection
   *
   * @param input String to be cleaned up
   * @return string with quotation mark removed or escaped
   */
  public String escapeQuotationMark(String input) {
    // TODO: check that this logic is safe to escape quotation mark to avoid code injection
    return input.replace("\"", "\\\"");
  }
}
