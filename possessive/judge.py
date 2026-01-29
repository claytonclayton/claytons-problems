from judging.judge_utils import judge_program_proportional

def judge(their_answer, language):
    return judge_program_proportional(__file__, their_answer, language)
