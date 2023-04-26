#include "pch.h"
#include "CppUnitTest.h"
#include "..\PatternVisitor\PatternVisitor.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		//���� ������������ ������ Number 
		TEST_METHOD(TestConstuctorNumber)
		{
			Number* n32 = new Number(32.0);
			Assert::IsTrue(n32->value() == 32.0);
		}
		//���� ������������ ������ ����������� ��� ������ Number
		TEST_METHOD(TestEvaluateNumber)
		{
			Number* n32 = new Number(32.0);
			Assert::IsTrue(n32->evaluate() == 32.0);
		}
		//���� ������ print(), ������� ���������� ��������� ������������� ��������� �������� ������� ������ Number
		
		TEST_METHOD(TestPrintNumber)
		{
			Number* n32 = new Number(32.0);
			Assert::IsTrue(n32->print() == to_string(32.0));
		}
		//���� ������������ ������  BinaryOperation 
		TEST_METHOD(TestConstuctorBinOperation)
		{
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
			Assert::IsTrue(minus->left() == n32 && minus->operation() == BinaryOperation::MINUS && minus->right() == n16);

		}
		//���� ������������ ������ ����������� �������� ���������
		TEST_METHOD(TestBinOperMinus) {
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
			Assert::IsTrue(minus->evaluate() == 16.0);
		}
		//���� ������������ ������ ����������� �������� ��������
		TEST_METHOD(TestBinOperPlus) {
			Number* n = new Number(-16.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* plus = new BinaryOperation(n, BinaryOperation::PLUS, n16);
			Assert::IsTrue(plus->evaluate() == 0.0);
		}
		//���� ������������ ������ ����������� �������� �������
		TEST_METHOD(TestBinOperDiv) {
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* div = new BinaryOperation(n32, BinaryOperation::DIV, n16);
			Assert::IsTrue(div->evaluate() == 2.0);
		}
		//���� ������������ ������ ����������� �������� �������, �������������� �������� ������� �� ����
		TEST_METHOD(TestBinOperDivByZero) {
			Number* n32 = new Number(32.0);
			Number* n0 = new Number(0.0);
			BinaryOperation* div_z = new BinaryOperation(n32, BinaryOperation::DIV, n0);
			Assert::ExpectException<std::invalid_argument>([div_z]() {div_z->evaluate(); });

		}
		//���� ������������ ������ ����������� �������� ���������
		TEST_METHOD(TestBinOperMul) {
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* mul = new BinaryOperation(n32, BinaryOperation::MUL, n16);
			Assert::IsTrue(mul->evaluate() == 512.0);
		}
		//���� ������ print(), ������� ���������� ��������� ������������� ��������� �������� ������� ������ BinaryOperation
		TEST_METHOD(TestBinOperPrint) {
			Number* n32 = new Number(32.0);
			Number* n16 = new Number(16.0);
			BinaryOperation* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
			Assert::IsTrue(minus->print() == to_string(32.0) + string(1, BinaryOperation::MINUS) + to_string(16.0));
		}
		//���� ������������ ������ FunctionCall
		TEST_METHOD(TestConstructorFuncCall) {
			Number* n16 = new Number(16.0);
			FunctionCall* callSqrt = new FunctionCall("sqrt", n16);
			Assert::IsTrue(callSqrt->arg() == n16 && callSqrt->name() == "sqrt");

		}
		//���� ������������ ������ �����������: ������� ���������� ����������� �����
		TEST_METHOD(TestEvaluteFuncCallSQRT) {
			Number* n16 = new Number(16.0);
			FunctionCall* callSqrt = new FunctionCall("sqrt", n16);
			Assert::IsTrue(callSqrt->evaluate() == 4.0);

		}
		//���� ������������ ������ �����������: �������������� �������� ������� ���������� ����������� ����� �������������� �����
		TEST_METHOD(TestEvaluteNegativeSQRTFuncCall) {
			Number* n16 = new Number(-16.0);
			FunctionCall* callSqrt = new FunctionCall("sqrt", n16);
			Assert::ExpectException<std::invalid_argument>([callSqrt]() {callSqrt->evaluate(); });

		}
		//���� ������������ ������ �����������: ������� ������ �����
		TEST_METHOD(TestEvaluteFuncCallABS) {
			Number* n16 = new Number(-16.0);
			FunctionCall* callSqrt = new FunctionCall("abs", n16);
			Assert::IsTrue(callSqrt->evaluate() == 16.0);

		}
		//���� ������������ ������ Value
		TEST_METHOD(TestConstructorValue) {
			Variable* var = new Variable("var");
			Assert::IsTrue(var->name() == "var");
		}
		//���� ������ print(), ������� ���������� ��������� ������������� ��������� �������� ������� ������ Value
		TEST_METHOD(TestPrintValue) {
			Variable* var = new Variable("var");
			Assert::IsTrue(var->print() == "var");
		}
		//���� ������������ ������ ����������� ������ Value :
		TEST_METHOD(TestEvaluateValue) {
			Variable* var = new Variable("var");
			Assert::IsTrue(var->evaluate() == 0.0);
		}

	};
}
