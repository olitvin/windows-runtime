#include "pch.h"

namespace NativeScript {
namespace Tests {

TEST_CLASS(ClassesTests) {
public:
    TEST_METHOD(EmptyClass) {
        MetadataReader metadataReader;

        const wchar_t* name{L"NativeScript.Tests.Fixtures.EmptyClass"};
        shared_ptr<ClassDeclaration> declaration{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(name))};

        Assert::IsTrue(declaration->name() == L"EmptyClass");
        Assert::IsTrue(declaration->fullName() == name);
        Assert::IsTrue(declaration->baseFullName() == L"System.Object");
    }

    TEST_METHOD(ImplementedInterfaces) {
        MetadataReader metadataReader;

        const wchar_t* name{L"NativeScript.Tests.Fixtures.SimpleClass"};
        shared_ptr<ClassDeclaration> declaration{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(name))};

        IteratorRange<ClassDeclaration::InterfaceIterator> interfaces{declaration->implementedInterfaces()};
        ClassDeclaration::InterfaceIterator it{interfaces.begin()};

        const unique_ptr<InterfaceDeclaration>& implementedInterface1{*it};
        Assert::IsTrue(implementedInterface1->fullName() == L"NativeScript.Tests.Fixtures.ISimpleClassClass");

        ++it;
        const unique_ptr<InterfaceDeclaration>& implementedInterface2{*it};
        Assert::IsTrue(implementedInterface2->fullName() == L"Windows.Foundation.IStringable");

        ++it;
        Assert::IsTrue(it == interfaces.end());
    }

    TEST_METHOD(Methods) {
        MetadataReader metadataReader;

        const wchar_t* name{L"NativeScript.Tests.Fixtures.SimpleClass"};
        shared_ptr<ClassDeclaration> declaration{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(name))};

        IteratorRange<ClassDeclaration::MethodIterator> methods{declaration->methods()};
        ClassDeclaration::MethodIterator it{methods.begin()};

        const MethodDeclaration& staticMethod{*it};
        Assert::IsTrue(staticMethod.name() == L"StaticMethod");
        Assert::IsTrue(staticMethod.fullName() == L"StaticMethod");
        Assert::IsTrue(staticMethod.isStatic() == true);
        Assert::IsTrue(staticMethod.isOverridable() == false);

        ++it;
        const MethodDeclaration& instanceMethod{*it};
        Assert::IsTrue(instanceMethod.name() == L"InstanceMethod");
        Assert::IsTrue(instanceMethod.fullName() == L"InstanceMethod");
        Assert::IsTrue(instanceMethod.isStatic() == false);
        Assert::IsTrue(instanceMethod.isOverridable() == false);

        ++it;
        Assert::IsTrue(it == methods.end());
    }

    TEST_METHOD(OverrideableMethods) {
        MetadataReader metadataReader;

        const wchar_t* name{L"Windows.UI.Xaml.Application"};
        shared_ptr<ClassDeclaration> declaration{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(name))};

        MethodDeclaration overridableMethod{declaration->findMethodsWithName(L"OnActivated")[0]};
        Assert::IsTrue(overridableMethod.isOverridable() == true);
    }

    TEST_METHOD(Properties) {
        MetadataReader metadataReader;

        const wchar_t* name{L"NativeScript.Tests.Fixtures.SimpleClass"};
        shared_ptr<ClassDeclaration> declaration{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(name))};

        IteratorRange<ClassDeclaration::PropertyIterator> properties{declaration->properties()};
        ClassDeclaration::PropertyIterator it{properties.begin()};

        const PropertyDeclaration& staticReadonlyProperty{*it};
        Assert::IsTrue(staticReadonlyProperty.name() == L"StaticReadonlyProperty");
        Assert::IsTrue(staticReadonlyProperty.fullName() == L"StaticReadonlyProperty");
        Assert::IsTrue(staticReadonlyProperty.getter().name() == L"get_StaticReadonlyProperty");
        Assert::IsTrue(staticReadonlyProperty.setter() == nullptr);
        Assert::IsTrue(staticReadonlyProperty.isStatic() == true);

        ++it;
        const PropertyDeclaration& instanceReadonlyProperty{*it};
        Assert::IsTrue(instanceReadonlyProperty.name() == L"InstanceReadonlyProperty");
        Assert::IsTrue(instanceReadonlyProperty.fullName() == L"InstanceReadonlyProperty");
        Assert::IsTrue(instanceReadonlyProperty.getter().name() == L"get_InstanceReadonlyProperty");
        Assert::IsTrue(instanceReadonlyProperty.setter() == nullptr);
        Assert::IsTrue(instanceReadonlyProperty.isStatic() == false);

        ++it;
        Assert::IsTrue(it == properties.end());
    }

    TEST_METHOD(Initializers) {
        MetadataReader metadataReader;

        shared_ptr<ClassDeclaration> activatableClass{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(L"NativeScript.Tests.Fixtures.ActivatableClass"))};

        IteratorRange<ClassDeclaration::MethodIterator> initializers{activatableClass->initializers()};

        ClassDeclaration::MethodIterator it{initializers.begin()};
        const MethodDeclaration& initializer0{*it};
        size_t index0{0};
        unique_ptr<InterfaceDeclaration> factory0{ClassDeclaration::declaringInterfaceForMethod(initializer0, &index0)};
        Assert::IsTrue(initializer0.isInitializer());
        Assert::IsTrue(initializer0.numberOfParameters() == 0);
        Assert::IsTrue(factory0 == nullptr);
        Assert::IsTrue(index0 == SIZE_T_MAX);

        ++it;
        const MethodDeclaration& initializer1{*it};
        size_t index1{0};
        unique_ptr<InterfaceDeclaration> factory1{ClassDeclaration::declaringInterfaceForMethod(initializer1, &index1)};
        Assert::IsTrue(initializer1.isInitializer());
        Assert::IsTrue(initializer1.numberOfParameters() == 1);
        Assert::IsTrue(factory1->id() == IID{0XE1C8B4D2, 0XCA7C, 0X5558,{0X7B, 0X6C, 0XAB, 0XC7, 0X47, 0XB8, 0X71, 0X3B}});
        Assert::IsTrue(index1 == 0);

        ++it;
        const MethodDeclaration& initializer2{*it};
        size_t index2{0};
        unique_ptr<InterfaceDeclaration> factory2{ClassDeclaration::declaringInterfaceForMethod(initializer2, &index2)};
        Assert::IsTrue(initializer2.isInitializer());
        Assert::IsTrue(initializer2.numberOfParameters() == 2);
        Assert::IsTrue(factory2->id() == IID{0XE1C8B4D2, 0XCA7C, 0X5558,{0X7B, 0X6C, 0XAB, 0XC7, 0X47, 0XB8, 0X71, 0X3B}});
        Assert::IsTrue(index2 == 1);

        ++it;
        Assert::IsTrue(it == initializers.end());
    }

    TEST_METHOD(ClassType) {
        MetadataReader metadataReader;

        shared_ptr<ClassDeclaration> emptyClass{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(L"NativeScript.Tests.Fixtures.EmptyClass"))};
        Assert::IsTrue(emptyClass->isInstantiable() == false);
        Assert::IsTrue(emptyClass->isSealed() == true);

        shared_ptr<ClassDeclaration> activatableClass{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(L"NativeScript.Tests.Fixtures.ActivatableClass"))};
        Assert::IsTrue(activatableClass->isInstantiable() == true);
        Assert::IsTrue(activatableClass->isSealed() == true);

        shared_ptr<ClassDeclaration> composableClass{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(L"Windows.UI.Xaml.Controls.ListView"))};
        Assert::IsTrue(composableClass->isInstantiable() == true);
        Assert::IsTrue(composableClass->isSealed() == false);

        shared_ptr<ClassDeclaration> abstractClass{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(L"Windows.UI.Xaml.Controls.Control"))};
        Assert::IsTrue(abstractClass->isInstantiable() == false);
        Assert::IsTrue(abstractClass->isSealed() == false);
    }

    // TEST_METHOD(StaticAttribute) {
    //     MetadataReader metadataReader;
    //
    //     shared_ptr<ClassDeclaration> emptyClass{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(L"NativeScript.Tests.Fixtures.EmptyClass"))};
    //     Assert::IsTrue(emptyClass->staticInterface() == nullptr);
    //
    //     shared_ptr<ClassDeclaration> simpleClass{dynamic_pointer_cast<ClassDeclaration>(metadataReader.findByName(L"NativeScript.Tests.Fixtures.SimpleClass"))};
    //     Assert::IsTrue(simpleClass->staticInterface()->fullName() == L"NativeScript.Tests.Fixtures.ISimpleClassStatic");
    //     Assert::IsTrue(simpleClass->staticInterface()->id() == IID{0xF07E1852, 0xC1F3, 0x5BE8,{0x5A, 0x6F, 0x6A, 0xC5, 0x36, 0xDE, 0x8E, 0xEB}});
    // }
};

}
}
