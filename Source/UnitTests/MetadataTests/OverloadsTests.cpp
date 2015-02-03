#include "UnitTests-Prefix.h"

namespace NativeScript {
namespace UnitTests {

    TEST_CLASS(OverloadsTests){
        public :
            TEST_METHOD(MethodOverloads){
                const wchar_t * name{ L"NativeScript.TestFixtures.OverloadsClass" };
    const ClassDeclaration* declaration{ static_cast<const ClassDeclaration*>(MetadataReader::findByName(name)) };
    vector<const MethodDeclaration> methods{ declaration->findMethodsWithName(L"InstanceMethod") };

    Assert::IsTrue(methods.size() == 2);

    const MethodDeclaration& method1{ methods[0] };
    Assert::IsTrue(method1.name() == L"InstanceMethod");
    Assert::IsTrue(method1.isDefaultOverload() == true);

    const MethodDeclaration& method2{ methods[1] };
    Assert::IsTrue(method2.name() == L"InstanceMethod");
    Assert::IsTrue(method2.overloadName() == L"InstanceMethodWithInt");
    Assert::IsTrue(method2.isDefaultOverload() == false);
}
};
}
}
