#include "pch.h"
#include "CppUnitTest.h"
#include "..\PatternVisitor\PatternVisitor.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		//тест конструктора класса Number 
		TEST_METHOD(TestConstuctorNumber)
		{
			Number* n32 = new Number(32.0);
			Assert::IsTrue(n32->value() == 32.0);
		}
		//тест виртуального метода «вычислить» для класса Number
		TEST_METHOD(TestEvaluateNumber)
		{
			Number* n32 = new Number(32.0);
			Assert::IsTrue(n32->evaluate() == 32.0);
		}
		//тест метода print(), который возвращает строковое представление числового значения объекта класса Number
		
		TEST_METHOD(TestPrintNumber)
		{
			Number* n32 = new Number(32.0);
			Assert::IsTrue(n32->print() == to_string(32.0));
		}
		//тест конструктора класса  BinaryOperation 
		TEST_METHOD(TestConstuctorBinOperation)
		{
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
			Assert::IsTrue(minus->left() == n32 && minus->operation() == BinaryOperation::MINUS && minus->right() == n16);

		}
		//тест виртуального метода «вычислить» операция вычитание
		TEST_METHOD(TestBinOperMinus) {
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
			Assert::IsTrue(minus->evaluate() == 16.0);
		}
		//тест виртуального метода «вычислить» операция сложение
		TEST_METHOD(TestBinOperPlus) {
			Number* n = new Number(-16.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* plus = new BinaryOperation(n, BinaryOperation::PLUS, n16);
			Assert::IsTrue(plus->evaluate() == 0.0);
		}
		//тест виртуального метода «вычислить» операция деления
		TEST_METHOD(TestBinOperDiv) {
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* div = new BinaryOperation(n32, BinaryOperation::DIV, n16);
			Assert::IsTrue(div->evaluate() == 2.0);
		}
		//тест виртуального метода «вычислить» операция деления, исключительная ситуация деление на ноль
		TEST_METHOD(TestBinOperDivByZero) {
			Number* n32 = new Number(32.0);
			Number* n0 = new Number(0.0);
			BinaryOperation* div_z = new BinaryOperation(n32, BinaryOperation::DIV, n0);
			Assert::ExpectException<std::invalid_argument>([div_z]() {div_z->evaluate(); });

		}
		//тест виртуального метода «вычислить» операция умножение
		TEST_METHOD(TestBinOperMul) {
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* mul = new BinaryOperation(n32, BinaryOperation::MUL, n16);
			Assert::IsTrue(mul->evaluate() == 512.0);
		}
		//тест метода print(), который возвращает строковое представление числового значения объекта класса BinaryOperation
		TEST_METHOD(TestBinOperPrint) {
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
			Assert::IsTrue(minus->print() == to_string(32.0) + string(1, BinaryOperation::MINUS) + to_string(16.0));
		}
		//тест конструктора класса FunctionCall
		TEST_METHOD(TestConstructorFuncCall) {
			Number* n16 = new Number(16.0);
			FunctionCall* callSqrt = new FunctionCall("sqrt", n16);
			Assert::IsTrue(callSqrt->arg() == n16 && callSqrt->name() == "sqrt");

		}
		//тест виртуального метода «вычислить»: функция извлечения квадратного корня
		TEST_METHOD(TestEvaluteFuncCallSQRT) {
			Number* n16 = new Number(16.0);
			FunctionCall* callSqrt = new FunctionCall("sqrt", n16);
			Assert::IsTrue(callSqrt->evaluate() == 4.0);

		}
		//тест виртуального метода «вычислить»: исключительная ситуация функция извлечения квадратного корня отрицательного числа
		TEST_METHOD(TestEvaluteNegativeSQRTFuncCall) {
			Number* n16 = new Number(-16.0);
			FunctionCall* callSqrt = new FunctionCall("sqrt", n16);
			Assert::ExpectException<std::invalid_argument>([callSqrt]() {callSqrt->evaluate(); });

		}
		//тест виртуального метода «вычислить»: функция модуль числа
		TEST_METHOD(TestEvaluteFuncCallABS) {
			Number* n16 = new Number(-16.0);
			FunctionCall* callSqrt = new FunctionCall("abs", n16);
			Assert::IsTrue(callSqrt->evaluate() == 16.0);

		}
		//тест конструктора класса Value
		TEST_METHOD(TestConstructorValue) {
			Variable* var = new Variable("var");
			Assert::IsTrue(var->name() == "var");
		}
		//тест метода print(), который возвращает строковое представление числового значения объекта класса Value
		TEST_METHOD(TestPrintValue) {
			Variable* var = new Variable("var");
			Assert::IsTrue(var->print() == "var");
		}
		//тест виртуального метода «вычислить» класса Value :
		TEST_METHOD(TestEvaluateValue) {
			Variable* var = new Variable("var");
			Assert::IsTrue(var->evaluate() == 0.0);
		}

	};
}
